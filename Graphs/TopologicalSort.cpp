#include <bits/stdc++.h>
using namespace std;

// Topological Sort Algorithm
// Based on the "Course Schedule" problem from CSES.

vector<int> graph[200005];
short mark[100005] = {0};
bool cycle = false;
vector<int> v;

void dfs(int node)
{
    mark[node] = 1;
    for (auto e : graph[node])
    {
        if (mark[e] == 0)
        {
            dfs(e);
        }
        else if (mark[e] == 1)
        {
            cycle = true;
        }
    }
    mark[node] = 2;
    v.push_back(node);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        pair<int,int> t;
        cin >> t.first >> t.second;
        graph[t.first].push_back(t.second);
    }

    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            dfs(i);
        }
    }

    if (cycle)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i+1 == v.size())
            {
                cout << '\n';
            }
            else
            {
                cout << ' ';
            }
        }
    }
    return 0;
}

