class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        long long lSum = 0, rSum = 0;
        int ans = 0;

        for (int num:nums) {
            lSum += num;
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            rSum += nums[i];
            lSum -= nums[i];

            if (lSum >= rSum)
                ans++;
        }

        return ans;
    }
};