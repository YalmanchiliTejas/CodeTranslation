import sys
import math
import itertools

nums = list(map(int, list(input())))
k = int(input())

dp0 = [[0 for _ in range(3)] for _ in range(len(nums))]
dp1 = [[0 for _ in range(3)] for _ in range(len(nums))]

dp0[0][0] = nums[0] - 1
dp1[0][0] = 1

for i in range(1, len(nums)):
	if nums[i] > 0:
		dp0[i][0] = dp0[i - 1][0] + dp1[i - 1][0] + 9
		dp0[i][1] = dp0[i - 1][1] + dp1[i - 1][1] + dp0[i - 1][0] * 9 + dp1[i - 1][0] * (nums[i] - 1)
		dp0[i][2] = dp0[i - 1][2] + dp1[i - 1][2] + dp0[i - 1][1] * 9 + dp1[i - 1][1] * (nums[i] - 1)
		dp1[i][0] = 0
		dp1[i][1] = dp1[i - 1][0] 
		dp1[i][2] = dp1[i - 1][1]
	else:
		dp0[i][0] = dp0[i - 1][0] + 9
		dp0[i][1] = dp0[i - 1][1] + dp0[i - 1][0] * 9
		dp0[i][2] = dp0[i - 1][2] + dp0[i - 1][1] * 9
		dp1[i][0] = dp1[i - 1][0] 
		dp1[i][1] = dp1[i - 1][1] 
		dp1[i][2] = dp1[i - 1][2]


print(dp0[-1][k-1] + dp1[-1][k-1])