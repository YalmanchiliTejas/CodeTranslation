n=int(input())
A=[int(i) for i in input().split()]

dp=[[0 for _ in range(n+1)] for _ in range(n+1)]

for w in range(n):
    for l in range(n-w):
        r=w+l+1
        dp[l][r] = max(-dp[l+1][r]+A[l],-dp[l][r-1]+A[r-1])
print(dp[0][-1])