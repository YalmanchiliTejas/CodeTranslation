def main():
    N = int(input())
    a = list(map(int, input().split()))
    # 互いにできるだけ点数を高くしたい
    # 単に先頭と末尾を比較して大きい方を選択した場合には、選択した要素の次の要素のほうが大きい場合がある
    # dp[i][j]で左からi番目からj-1番目までだけ残っている場合にそこからとり得る最大値を考える
    # dp[0][0]

    dp = [[0 for i in range(N)] for j in range(N)]

    for i in range(N):
        dp[i][i] = a[i]

    for i in range(N-1, -1, -1):
        for j in range(i+1, N):
            right = a[i] - dp[i+1][j]
            left = a[j] - dp[i][j-1]
            if right > left:
                dp[i][j] = right
            else:
                dp[i][j] = left
    # print(dp)
    print(dp[0][N-1])


main()
