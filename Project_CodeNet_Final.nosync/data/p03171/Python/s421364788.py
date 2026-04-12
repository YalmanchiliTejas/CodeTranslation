#!/mnt/c/Users/moiki/bash/env/bin/python
# FROM : https://atcoder.jp/contests/dp/tasks/dp_l
# N,M = map(int, input().split())
N = int(input())
# A = list(map(int, input().split()))
A = tuple(map(int, input().split()))

dp = [ [0]*(N+1) for _ in range(N+1)]
for d in range(1,N+1):
    for l in range(N+1-d):
        r = l+d
        dp[l][r] = \
        max(
            A[l] - dp[l+1][r],
            A[r-1] - dp[l][r-1]
                )
print(dp[0][N])
