
def main():
    ns = input()
    k = int(input())

    l = len(ns)

    dp = [[0, 0] for _ in range(k+1)]
    dp[0][0] = 1

    for i in range(l):
        c = int(ns[i])

        dp_n = [[0, 0] for _ in range(k+1)]

        for j in range(k + 1):
            if c == 0:
                dp_n[j][0] += dp[j][0]
            else:
                dp_n[j][1] += dp[j][0]
                if j+1 <= k:
                    dp_n[j+1][1] += dp[j][0] * (c - 1)
                    dp_n[j+1][0] += dp[j][0]

            dp_n[j][1] += dp[j][1]
            if j+1 <= k:
                dp_n[j+1][1] += dp[j][1] * 9

        dp = dp_n

    print(dp[k][0] + dp[k][1])


main()
