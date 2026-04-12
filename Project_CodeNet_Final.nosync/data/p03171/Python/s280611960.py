

def submit():
    n = int(input())
    a = list(map(int, input().split()))

    # dp[i][j] : i ~ j - 1までの数列におけるX - Yのスコア
    # taroのターンの場合、
    #   max(dp[i + 1][j] + iスコア, dp[i][j - 1] + jスコア)
    # jiroのターンの場合
    #   min(dp[i + 1][j] - iスコア, dp[i][j - 1] - jスコア)

    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][i] = 0

    # len = 1, 2, 3, ...と求めてゆく
    # len = xのとき、dp[i + 1][j]かdp[i][j - 1]はlen = x - 1のときのスコアなので
    # 計算済み
    for l in range(1, n + 1):
        for i in range(n):
            j = i + l
            if j > n:
                break
            
            # taroのターン, nとlの偶奇が一致する時
            if (n - l) % 2 == 0:
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1])
            else:
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1])

    print(dp[0][n])
            

submit()