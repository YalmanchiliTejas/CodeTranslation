N,a,b,c,d = map(int,input().split())

fact = [0]*(N+1)
ifact = [0]*(N+1)
inv = [0]*(N+1)
p=10**9+7

def combination(n):
    fact[0] = 1
    fact[1] = 1
    ifact[0] = 1
    ifact[1] = 1
    inv[1] = 1
    for i in range(2,n+1):
        fact[i] = (fact[i-1]*i)%p
        inv[i] = p - inv[p%i]*(p//i)%p
        ifact[i] = (ifact[i-1]*inv[i])%p
def op(n,k):
    if k<0 or k>n or n<0:
        return 0
    return (fact[n]*ifact[k]*ifact[n-k])%p

combination(N)

dp = [[0]*(N+1) for _ in range(b-a+2)]
dp[0][0] = 1
for i in range(b-a+1):
    step = i+a
    fa = fact[step]
    inv_Af = pow(fact[step],p-2,p)
    for j in range(N+1):
        val = dp[i][j]%p
        if val==0:
            continue
        dp[i+1][j] = (dp[i+1][j] + val)%p
        if j+c*step > N:
            continue
        tmp = pow(fa,(c-1)*(p-2), p)
        for k in range(c,d+1):
            idx = k*step
            if j+idx > N:
                break
            val2 = (op(N-j,idx) * fact[idx])%p
            tmp *= inv_Af
            tmp %= p
            val3 = (val2 * ifact[k]*tmp)%p
            dp[i+1][j+idx] += val*val3
print(dp[-1][-1]%p)
