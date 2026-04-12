N, S = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
MOD =   998244353
DP = [[0 for p in range(S+1)]for x in range(N)]
ans = N * (A[0]==S)
if A[0]<=S:
    DP[0][A[0]] = 1
for n,a in enumerate(A):
    if n!=0:
        #もらう
        for p in range(a,S+1):
            DP[n][p] += DP[n-1][p-a]
        for p in range(S+1):
            DP[n][p] += DP[n-1][p]
            DP[n][p] %= MOD
        #初期化
        if a<=S:DP[n][a] += n+1
    ans += (DP[n][S]*(N-n))% MOD
    DP[n][S] = 0
    ans %= MOD
print(ans)