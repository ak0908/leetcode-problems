class Solution {
public:
    int getMaxEnemyScore(vector<int>& nums, int l, int r, map<string, int>& memo){
        if(l == r){
            return nums[l];
        }
        
        string key = to_string(l) + ":" + to_string(r);
        // if this sub problem has already been calculated. then we don't need to continue
        // we can just return the value we stored in our memo dictionary or map
        if (memo.find(key) != memo.end()) return memo.find(key)->second;
        
        // The user has 2 choices. either pick the most left number or the mose right number
        // from this two desicions, we would like to pick the max. because both players would
        // like to maximize their chances of winnning.
        memo[key] =  max(nums[l] - getMaxEnemyScore(nums, l+1, r, memo), nums[r] - getMaxEnemyScore(nums,l, r-1, memo));
        
        return memo[key];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        map<string, int> memo;  // this is the dictionary to store those already calculated sub problems
        return getMaxEnemyScore(nums, 0, nums.size() -1, memo) >= 0;
    }
};