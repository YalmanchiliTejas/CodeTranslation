N = int(input())
K = int(input())

strN = str(N)
maxD = len(strN)

dp = [[[0]*(K+1) for j in range(2)] for i in range(maxD+1)]
dp[0][0][0] = 1
for d, Nd in enumerate(strN):
    Nd = int(Nd)
    for isLeN in range(2):
        for m in range(K+1):
            x = 0
            if not isLeN and x > Nd: continue
            isLeN2 = isLeN or x < Nd
            dp[d+1][isLeN2][m] += dp[d][isLeN][m]
            for x in range(1, 10):
                if not isLeN and x > Nd: continue
                isLeN2 = isLeN or x < Nd
                m2 = m+1
                if m2 > K: continue
                dp[d+1][isLeN2][m2] += dp[d][isLeN][m]
#    print(d+1, Nd, dp[d+1])

#print(dp[-1])
print(dp[-1][0][K]+dp[-1][1][K])
