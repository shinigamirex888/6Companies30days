#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, int i)
    {
        isConnected[i][i] = 0;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1)
            {
                isConnected[i][j] = 0;
                if (isConnected[j][j] == 1)
                {
                    dfs(isConnected, j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int ans = 0;
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
        {
            if (isConnected[i][i] == 0)
                continue;
            ans++;
            dfs(isConnected, i);
        }
        return ans;
    }
};