S = input()
K = int(input())


# digit DP
def digit_dp(S,K):
    L = len(S)
    # dp[i][0] = 今のところぴったり
    # dp[i][1] = すでにSより小さいと確定している
    dp = [[[0 for k in range(K+1)] for j in range(2)] for i in range(L+1)]
    dp[0][0][0] = 1

    for i in range(L):
        D = int(S[i])
        for j in range(2):
            for d in range((9 if j else D)+1):
                for k in range(K+1):
                    if d != 0:
                        if k == K:
                            continue
                        dp[i+1][j or d<D][k+1] += dp[i][j][k]
                    else:
                        dp[i+1][j or d<D][k] += dp[i][j][k]

    return dp[L][0][K] + dp[L][1][K]         # 非負整数の数え上げ(0を含む)

print(digit_dp(S,K))
