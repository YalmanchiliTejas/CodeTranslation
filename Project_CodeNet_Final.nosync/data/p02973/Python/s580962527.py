import sys
from bisect import bisect

n = int(input())
aaa = list(map(int, sys.stdin.readlines()))

dp = [1]
for a in aaa:
    a *= -1
    i = bisect(dp, a)
    if i < len(dp):
        dp[i] = a
    else:
        dp.append(a)
print(len(dp))
