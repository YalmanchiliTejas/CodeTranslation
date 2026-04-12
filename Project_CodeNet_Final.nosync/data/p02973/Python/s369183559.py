from sys import *
from bisect import *

n = int(input())
a = list(map(int, stdin.readlines()))

dp = [1]
for j in a:
    j *= -1
    i = bisect(dp, j)
    if i < len(dp):
        dp[i] = j
    else:
        dp.append(j)
print(len(dp))