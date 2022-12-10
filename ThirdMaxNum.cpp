class Solution {
public:
    int thirdMax(vector<int>& nums) {

        vector<int> result;

        if(nums.size() == 1)
            return nums[0];

        for(int i = 0; i < nums.size() - 1; i++) {

            for(int j = 0; j < nums.size() - i - 1; j++) {
                if(nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
             
            if(i == 0 || (nums[nums.size() - (i+1)] != result[result.size()-1]))
                result.push_back(nums[nums.size() - (i+1)]);

            if(result.size() == 3)
                break;
        }
        
        if(result.size() != 3 && nums[0] != result[result.size()-1])
            result.push_back(nums[0]);

        if(result.size() < 3)
            return result[0];

        return result[result.size() - 1];
    }
};