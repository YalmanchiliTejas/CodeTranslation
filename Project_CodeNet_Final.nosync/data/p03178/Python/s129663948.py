K = input()
D = int(input())
lenK = len(K)
mod = 10**9+7
#dp[i][smaller][k]はi桁まで見たあまりkの物の数とする.ただしsmaller=0のときはまだK以下かわかってないとする. 
dp = [[[0]*D for i in range(2)] for _ in range(lenK + 1)]
dp[0][0][0] = 1
for i,c in enumerate(K):
    for less in range(2):
        lim = 9 if less else int(c)
        for r in range(D):
            for d in range(lim+1):
                dp[i+1][less or d < lim][(r+d)%D] += dp[i][less][r]
                dp[i+1][less or d < lim][(r+d)%D] %= mod
print((dp[-1][0][0] + dp[-1][1][0] - 1)%mod)