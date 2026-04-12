# Author: S Mahesh Raju
# Username: maheshraju2020
# Date: 01/08/2020

from sys import stdin, stdout, setrecursionlimit
from math import gcd, ceil, sqrt
from collections import Counter
from bisect import bisect_left, bisect_right
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
setrecursionlimit(100000)
mod = 1000000007

n = ii1()
arr = iia()
dp = [[0 for i in range(n + 1)] for j in range(n + 1)]
for i in range(1, n + 1)[::-1]:
    for j in range(i, n + 1):
        if i == j:
            dp[i][j] = arr[i - 1]
        else:
            dp[i][j] = max(arr[i - 1] - dp[i + 1][j], arr[j - 1] - dp[i][j - 1]
        )
print(dp[1][-1])