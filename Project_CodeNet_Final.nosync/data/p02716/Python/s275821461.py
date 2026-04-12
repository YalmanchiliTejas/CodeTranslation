N = int(input())
A = list(map(int,input().split()))
s = [0]*N
for i in range(N):
    s[i] = s[i-2]+A[i]

dp = [0]*N
dp[1] = max(A[0],A[1])
if N>=3:
    dp[2] = max(A[0],A[1],A[2])
for n in range(3,N):
    if n%2==1:
        dp[n] = max(A[n]+dp[n-2],s[n-1])
    else:
        dp[n] = max(A[n]+dp[n-2],A[n-1]+dp[n-3],s[n-2])

print(dp[-1])