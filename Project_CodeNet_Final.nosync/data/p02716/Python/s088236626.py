if __name__ == '__main__':
    from sys import stdin
    input = stdin.readline
    from collections import Counter

    import random

    n = int(input())
    aa = list(map(int, input().split()))
    if n%2 == 0:
        dp = [[0]*n for _ in range(2)]
        dp[0][0] = aa[0]
        dp[1][1] = aa[1] if aa[1]>aa[0] else aa[0]
        for i in range(2, n, 2):
            aa_i = aa[i]
            dp[0][i] = dp[0][i-2]+ aa_i

            aa_i_p_1 = aa[i+1]
            dp_i_1 = dp[1][i-1]
            next = (dp_i_1+aa_i_p_1) if (dp_i_1+aa_i_p_1 > dp[0][i]) else dp[0][i]
            dp[1][i+1] = next
        print(dp[1][n-1])

    else:
        dp = [[0]*n for _ in range(3)]
        dp[0][0] = aa[0]
        dp[1][1] = aa[1] if aa[1]>aa[0] else aa[0]
        for i in range(2, n, 2):
            aa_i = aa[i]
            dp[0][i] = dp[0][i-2]+ aa_i
            dp_i_2 = dp[2][i-2]
            dp[2][i] = dp_i_2+aa_i if dp_i_2+aa_i > dp[1][i-1] else dp[1][i-1]

            if i == n-1:
                break
            aa_i_p_1 = aa[i+1]
            dp_i_1 = dp[1][i-1]
            dp[1][i+1] = dp_i_1+aa_i_p_1 if dp_i_1+aa_i_p_1 > dp[0][i] else dp[0][i]
        print(dp[2][n-1])