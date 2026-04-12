N = input()
L = len(N)
K = int(input())

dp = [[[0]*2 for _ in range(K+1)] for _ in range(L+1)]
dp[0][0][0] = 1
for i,c in enumerate(N):
    c = int(c)
    for k in range(K+1):
        for less in range(2):
            for d in range(10):
                nk = k + (d>0)
                if nk > K: continue
                if less == 0 and d > c: continue
                nxless = not(less==0 and d==c)
                dp[i+1][nk][nxless] += dp[i][k][less]
print(sum(dp[-1][-1]))