import sys
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
A = list(map(int, input().split()))
dp = [0] * (s + 1)
ans = 0
for i in range(n):
    dp[0] += 1
    for j in range(s, A[i] - 1, -1):
        dp[j] += dp[j - A[i]]
        dp[j] %= mod
    ans += dp[s]
    ans %= mod
print(ans)
