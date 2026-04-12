import bisect
from collections import deque
N = int(input())
nums = deque()

for i in range(N):
    temp =  int(input())
    ind = bisect.bisect_left(nums, temp)
    if ind == 0:
        nums.appendleft(temp)
    else:
        nums[ind - 1] = temp
print(len(nums))