#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Helper function to perform topological sort
vector<int> topologicalSort(int n, unordered_map<int, vector<int>>& adjList, vector<int>& indegree) {
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adjList[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != n) {
        return {}; // Cycle detected
    }

    return result;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    // Step 1: Assign unique groups for items with group[i] == -1
    int newGroupId = m;
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) {
            group[i] = newGroupId++;
        }
    }

    // Step 2: Build item-level and group-level graphs
    unordered_map<int, vector<int>> itemGraph, groupGraph;
    vector<int> itemIndegree(n, 0), groupIndegree(newGroupId, 0);

    for (int i = 0; i < n; i++) {
        for (int before : beforeItems[i]) {
            itemGraph[before].push_back(i);
            itemIndegree[i]++;
            if (group[before] != group[i]) {
                groupGraph[group[before]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
    }

    // Step 3: Topological sort for items and groups
    vector<int> itemOrder = topologicalSort(n, itemGraph, itemIndegree);
    if (itemOrder.empty()) return {}; // Cycle detected in item graph

    vector<int> groupOrder = topologicalSort(newGroupId, groupGraph, groupIndegree);
    if (groupOrder.empty()) return {}; // Cycle detected in group graph

    // Step 4: Group items based on the sorted group order
    unordered_map<int, vector<int>> groupToItems;
    for (int item : itemOrder) {
        groupToItems[group[item]].push_back(item);
    }

    vector<int> result;
    for (int grp : groupOrder) {
        result.insert(result.end(), groupToItems[grp].begin(), groupToItems[grp].end());
    }

    return result;
}

int main() {
    // Example 1
    int n1 = 8, m1 = 2;
    vector<int> group1 = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems1 = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    vector<int> result1 = sortItems(n1, m1, group1, beforeItems1);
    for (int item : result1) {
        cout << item << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 8, m2 = 2;
    vector<int> group2 = {-1, -1, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> beforeItems2 = {{}, {6}, {5}, {6}, {3}, {}, {4}, {}};
    vector<int> result2 = sortItems(n2, m2, group2, beforeItems2);
    if (result2.empty()) {
        cout << "[]" << endl;
    } else {
        for (int item : result2) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
