#include <bits/stdc++.h>
using namespace std;

short visited[100000] = {0};
vector<int> graph[100000];
bool has_cycle = false;

void dfs(int node, int parent)
{
    visited[node] = 1;

    for (auto neighbor : graph[node])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor, parent);
        }
        else if (visited[neighbor] == 1 && neighbor != parent)
        {
            has_cycle = true;
        }
    }

    visited[node] = 2;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> edge;
        cin >> edge.first >> edge.second;

        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    dfs(1, -1);

    if (has_cycle)
    {
        cout << "Graph has a cycle.\n";
    }
    else
    {
        cout << "Graph does not contain a cycle.\n";
    }

    return 0;
}

