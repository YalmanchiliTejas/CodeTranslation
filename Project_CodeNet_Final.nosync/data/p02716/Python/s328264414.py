def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    if n < 4:
        print(max(a))
        return
    odd = n % 2 == 1
    if odd:
        dp = [[0] * 3 for _ in range(n)]
    else:
        dp = [[0] * 2 for _ in range(n)]
    dp[0][0] = a[0]
    dp[1][1] = a[1]
    if odd:
        dp[2][2] = a[2]
    for i in range(2, n, 2):
        dp[i][0] = dp[i - 2][0] + a[i]
    for i in range(3, n, 2):
        dp[i][1] = max(dp[i - 2][1] + a[i], dp[i - 3][0] + a[i])
    if odd:
        for i in range(4, n, 2):
            dp[i][2] = max(dp[i - 2][2] + a[i], dp[i - 3]
                           [1] + a[i], dp[i - 4][0] + a[i])
    if odd:
        print(max(dp[-1][-1], dp[-2][-2], dp[-3][-3]))
    else:
        print(max(dp[-1][-1], dp[-2][-2]))


if __name__ == '__main__':
    resolve()
