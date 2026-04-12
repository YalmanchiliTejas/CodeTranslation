from sys import stdin
from bisect import bisect

N = int(stdin.readline().rstrip())
A = []
for i in range(N):
    A.append(int(input()))

dp = []
for a in A[::-1]:
    i = bisect(dp, a)
    if i < len(dp):
        dp[i] = a
    else:
        dp.append(a)
print(len(dp))