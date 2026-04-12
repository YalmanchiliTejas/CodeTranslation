import sys
from copy import copy
input = sys.stdin.readline
'''
n, m = map(int, input().split())
n = int(input())
A = list(map(int, input().split()))
S = input().strip()
for test in range(int(input())):
'''
inf = 100000000000000000  # 1e17
mod = 998244353

n, s = map(int, input().split())
a = [0]
a += list(map(int, input().split()))
#  dp = [[0] * (3010)] * (n + 2)  #
dp = [[0]*(3010) for i in range(n+2)]

ans = 0
for i in range(1, 1 + 1):
    dp[i][a[i]] = i
if a[1] == s:
    ans += n
for i in range(2, n + 1):
    if a[i] < s:
        dp[i][a[i]] += i
    dp[i][a[i]] %= mod
    if s > a[i]:
        ans += (n - i + 1) * dp[i - 1][s - a[i]]  # = -> +=
    elif s == a[i]:
        ans += (n - i + 1) * i
    ans %= mod
    for j in range(a[i], s+1):  #
        dp[i][j] += dp[i - 1][j - a[i]]
        dp[i][j] %= mod
    for j in range(0, s+1):
        dp[i][j] += dp[i - 1][j]
        dp[i][j] %= mod
print(ans)
