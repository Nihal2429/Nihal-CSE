#include <vector>
using namespace std;

class Solution
{
    void mergeSort(vector<int>& nums, vector<int>& indexes,
                   vector<int>& temp, vector<int>& count,
                   int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, indexes, temp, count, left, mid);
        mergeSort(nums, indexes, temp, count, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int k = left;
        int rightCount = 0;

        while (i <= mid && j <= right)
        {
            if (nums[indexes[j]] < nums[indexes[i]])
            {
                temp[k++] = indexes[j++];
                rightCount++;
            }
            else
            {
                count[indexes[i]] += rightCount;
                temp[k++] = indexes[i++];
            }
        }

        while (i <= mid)
        {
            count[indexes[i]] += rightCount;
            temp[k++] = indexes[i++];
        }

        while (j <= right)
        {
            temp[k++] = indexes[j++];
        }

        for (int p = left; p <= right; p++)
        {
            indexes[p] = temp[p];
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> count(n, 0);
        vector<int> indexes(n);
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {
            indexes[i] = i;
        }

        if (n > 0)
        {
            mergeSort(nums, indexes, temp, count, 0, n - 1);
        }

        return count;
    }
};