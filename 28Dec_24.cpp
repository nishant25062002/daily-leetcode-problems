#include <bits/stdc++.h>
using namespace std;
long long n, t;
#define ll long long

int dp(vector<int> &sums, int k, int idx, int rem,
       vector<vector<int>> &memo)
{
    if (rem == 0)
        return 0;
    if (idx >= sums.size())
    {
        return rem > 0 ? INT_MIN : 0;
    }

    if (memo[idx][rem] == -1)
    {
        int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int skipCurrent = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = max(withCurrent, skipCurrent);
    }

    return memo[idx][rem];
}

void dfs(vector<int> &sums, int k, int idx, int rem,
         vector<vector<int>> &memo, vector<int> &indices)
{
    if (rem == 0)
        return;
    if (idx >= sums.size())
        return;

    int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
    int skipCurrent = dp(sums, k, idx + 1, rem, memo);

    if (withCurrent >= skipCurrent)
    {
        indices.push_back(idx);
        dfs(sums, k, idx + k, rem - 1, memo, indices);
    }
    else
    {
        dfs(sums, k, idx + 1, rem, memo, indices);
    }
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    int k = 2;

    int n = nums.size() - k + 1;
    int sum = 0;
    vector<int> sums;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    sums.push_back(sum);

    for (int i = 1; i <= nums.size() - k; i++)
    {
        sum -= nums[i - 1];
        sum += nums[i + k - 1];
        sums.push_back(sum);
    }

    vector<vector<int>> memo(n, vector<int>(4, -1));
    vector<int> indices;

    dfs(sums, k, 0, 3, memo, indices);

    // indices vector is the ans;
    // return indices;

    for (auto i : indices)
    {
        cout << i << " ";
    }
    
    return 0;
}