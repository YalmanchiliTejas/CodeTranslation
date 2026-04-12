def main():
    a = input()
    b = int(input())
    n = len(a)

    dp = [[[0 for _ in range(2)] for _ in range(b+1)] for _ in range(n+1)]
    dp[0][0][0] = 1

    for i in range(n):
        nd = int(a[i])
        for j in range(b+1):
            for k in range(2):
                for d in range(10):
                    ni = i+1
                    nj = j
                    nk = k
                    if d != 0:
                        nj += 1
                    if nj > b:
                        continue
                    if k == 0:
                        if d > nd:
                            continue
                        if d < nd:
                            nk = 1
                    dp[ni][nj][nk] += dp[i][j][k]

    ans = dp[n][b][0] + dp[n][b][1]
    print(ans)


main()
