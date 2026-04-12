MAX = 10**6+100
MOD = 10**9+7
fact = [0]*MAX #fact[i]: i!
inv = [0]*MAX #inv[i]: iの逆元
finv = [0]*MAX #finv[i]: i!の逆元
fact[0] = 1
fact[1] = 1
finv[0] = 1
finv[1] = 1
inv[1] = 1
    
for i in range(2, MAX):
    fact[i] = fact[i-1]*i%MOD
    inv[i] = MOD-inv[MOD%i]*(MOD//i)%MOD
    finv[i] = finv[i-1]*inv[i]%MOD

def Com(n, r):
    if n<r:
        return 0
    if n<0 or r<0:
        return 0
    return fact[n]*(finv[r]*finv[n-r]%MOD)%MOD

N, A, B, C, D = map(int, input().split())
dp = [[0]*(N+1) for _ in range(B-A+2)]
dp[0][0] = 1

for i in range(B-A+1):
    for j in range(N+1):
        m = 1
        
        for k in range(min(D, (N-j)//(i+A))+1):
            if k==0 or C<=k:
                dp[i+1][j+(i+A)*k] += m*finv[k]*dp[i][j]
                dp[i+1][j+(i+A)*k] %= MOD
            
            m *= Com(N-j-(i+A)*k, i+A)
            m %= MOD
            
print(dp[B-A+1][N])
