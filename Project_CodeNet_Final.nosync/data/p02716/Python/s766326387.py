N = int(input())
A = list(map(int,input().split()))
s = [0]*N
for i in range(N):
    s[i] = s[i-2]+A[i]

dp = [0]*N
for n in range(N):
    if n%2==1:
        dp[n] = max(A[n]+dp[n-2],s[n-1])
    else:
        dp[n] = max(A[n]+dp[n-2],dp[n-1])

print(dp[-1])