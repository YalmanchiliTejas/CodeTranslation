def solve():
    from sys import stdin
    f_i = stdin
    
    N = int(f_i.readline())
    K = int(f_i.readline())
    S = str(N)
    
    
    import numpy as np
    # dp[digit][below flag][number of non-0]
    dp = np.zeros((len(S) + 1, 2, K + 1), dtype=int)
    dp[0][0][0] = 1
    digits = (int(c) for c in S)
    
    for i, d in enumerate(digits):
        for j in (0, 1):
            for k in range(K):
                if j:
                    dp[i+1][j][k+1] += dp[i][j][k] * 9
                    dp[i+1][j][k] += dp[i][j][k]
                else:
                    if d:
                        dp[i+1][1][k+1] += dp[i][j][k] * (d - 1)
                        dp[i+1][j][k+1] += dp[i][j][k]
                        dp[i+1][1][k] += dp[i][j][k]
                    else:
                        dp[i+1][j][k] += dp[i][j][k]
                    
    ans = np.sum(dp[:, :, K])
    
    print(ans)

solve()