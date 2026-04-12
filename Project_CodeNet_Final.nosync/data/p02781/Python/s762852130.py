def main():
    S = input()
    N = len(S)
    K = int(input())
    dp = [[[0]*(4) for j in range(2)] for i in range(N+1)]
    dp[0][0][0] = 1
    for i in range(N):
        for j in range(2):
            for k in range(4):
                lim = (9 if j else int(S[i]))
                for d in range(lim + 1):
                    if k + (d != 0) > 3:
                        continue
                    dp[i+1][j or d < lim][k + (d != 0)] += dp[i][j][k]
    ans = 0
    for j in range(2):
        ans += dp[N][j][K]
    print(ans)


if __name__ == '__main__':
    main()
