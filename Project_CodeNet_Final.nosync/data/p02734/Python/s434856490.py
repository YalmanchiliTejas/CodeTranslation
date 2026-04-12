mod = 998244353
N,S = map(int,input().split())
A = list(map(int,input().split()))

dp1 = [0]*(3001*N)
dp2 = [0]*(3001*N)

for n in range(N):
    for s in range(3000,-1,-1):
        dp2[n*N+s] = dp2[(n-1)*N+s]
        dp1[n*N+s] = dp1[(n-1)*N+s]
        if s>A[n]:
            dp2[n*N+s] += dp1[(n-1)*N+s-A[n]]*(N-n)
            dp1[n*N+s] += dp1[(n-1)*N+s-A[n]]
        elif s==A[n]:
            dp2[n*N+s] += (n+1)*(N-n)
            dp1[n*N+s] += n+1
        dp2[n*N+s] %= mod
        dp1[n*N+s] %= mod

print(dp2[(N-1)*N+S])