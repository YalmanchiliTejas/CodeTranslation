def solve2():
    N = raw_input()
    K = int(raw_input())
    L = len(N)
    digN = [int(d) for d in N]
    dp = [[[0 for k in range(2)] for j in range(K+1)] for i in range(L+1)]
    dp[0][0][0] = 1
    for i in range(L):
        for j in range(K+1):
            for k in range(2):
                for d in range(10):
                    ni = i + 1
                    nj = j
                    nk = k
                    if d != 0:
                        nj += 1
                    if nj > K:
                        continue
                    if k == 0:
                        if d > digN[i]:
                            continue
                        if d < digN[i]:
                            nk = 1
                    dp[ni][nj][nk] += dp[i][j][k]
    print dp[L][K][0] + dp[L][K][1]

if __name__ == '__main__':
    solve2()
