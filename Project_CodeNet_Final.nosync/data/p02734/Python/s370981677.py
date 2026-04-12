MOD = 998244353
N,S= map(int,input().split())
A= list(map(int,input().split()))


dp = [[0 for i in range(S+1)] for j in range(N+1)]
sumdp = [0 for i in range(S+1)]

dp[0][0] = 1
sumdp[0] = 1

for i in range(1,N+1):
    a = A[i-1]
    if a <= S:
        dp[i][a] += i
    for j in range(1,S+1):
        if j+a > S:
            break
        dp[i][j+a] += sumdp[j]
        dp[i][j+a] %= MOD
    for j in range(S+1):
        sumdp[j] = (sumdp[j] + dp[i][j]) % MOD
    
ans = 0
for i in range(1,N+1):
    ans = (ans + dp[i][S] * (N+1-i)) % MOD
print(ans % MOD)

