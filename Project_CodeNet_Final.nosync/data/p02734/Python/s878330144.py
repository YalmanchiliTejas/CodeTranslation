import sys
input = sys.stdin.readline

mod = 998244353
N, S = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
dp = [0] * (S+1)
for i in range(1, N+1):
    a = A[i-1]
    for j in range(a+1, S+1)[::-1]:
        dp[j] += dp[j-a]
    if a <= S:
        dp[a] += i
    ans += dp[S] * (N-i+1)
    ans %= mod
    dp[S] = 0
print(ans)