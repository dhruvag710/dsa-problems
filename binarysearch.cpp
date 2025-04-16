// 704. Binary Search 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(target< nums[mid])
            {
                high=mid-1;
            }
            else if(target > nums[mid])
            {
                low=mid+1;
            }
            else
            {
                return mid;
            }
            
        }
        return -1;
    }
};


// Lower Bound

class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;  // Default: if not found, return n

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= x) {
                ans = mid;       // possible answer
                high = mid - 1;  // search on left side
            } else {
                low = mid + 1;   // search on right side
            }
        }
        return ans;
    }
};

// Upper Bound
class Solution {
public:
    int upperBound(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;  // Default: if not found, return n

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > x) {
                ans = mid;       // possible answer
                high = mid - 1;  // search on left side
            } else {
                low = mid + 1;   // search on right side
            }
        }
        return ans;
    }
};

// 35. Search Insert Position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

// Floor and Ceil in Sorted Array
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int floor = -1, ceil = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                floor = ceil = x;
                break;
            } else if (nums[mid] < x) {
                floor = nums[mid];
                low = mid + 1;
            } else {
                ceil = nums[mid];
                high = mid - 1;
            }
        }

        return {floor, ceil};
    }
};
