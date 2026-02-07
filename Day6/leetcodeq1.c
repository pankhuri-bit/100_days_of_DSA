#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;
    for (int cur = 0; cur < numsSize; cur++) {
        if (nums[cur] != 0) {
            int temp = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[cur];
            nums[cur] = temp;
            lastNonZeroFoundAt++;
        }
    }
}
