def main():
    n = int(input())
    a = list(map(int, input().split()))

    su = [0 for _ in range(n + 1)]    
    for i in range(n):
        su[i + 1] = su[i] + a[i]

    INF = 1e18
    dp = [[-INF for _ in range(n + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][i] = 0

    for length in range(1, n + 1):
        i = 0
        while i + length <= n:
            j = i + length
            dp[i][j] = max(a[i] + (su[j] - su[i + 1]) - dp[i + 1][j], a[j - 1] + (su[j - 1] - su[i]) - dp[i][j - 1])
            i += 1
    
    print(dp[0][n] - (su[n] - dp[0][n]))

if __name__ == '__main__':
    main()