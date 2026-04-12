from collections import deque
from bisect import bisect_left
import sys
input = sys.stdin.readline

N = int(input())
A = [int(input()) for _ in range(N)]
nums = deque()
for i in range(N):
    j = bisect_left(nums, A[i])
    if j == 0:
        nums.appendleft(A[i])
    else:
        nums[j-1] = A[i]
print(len(nums))
