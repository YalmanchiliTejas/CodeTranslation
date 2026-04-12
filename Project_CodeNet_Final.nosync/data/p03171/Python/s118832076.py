def main():
    n = int(input())
    a = list(map(int, input().split()))

    su = [0 for _ in range(n + 1)]    
    for l in range(n):
        su[l + 1] = su[l] + a[l]

    INF = 1e18
    dp = [[-INF for _ in range(n + 1)] for _ in range(n + 1)]

    for l in range(n + 1):
        dp[l][l] = 0
    for length in range(1, n + 1):
        l = 0
        while l + length <= n:
            r = l + length
            dp[l][r] = max(a[l] + (su[r] - su[l + 1]) - dp[l + 1][r], 
                            a[r - 1] + (su[r - 1] - su[l]) - dp[l][r - 1])
            l += 1
    print(dp[0][n] - (su[n] - dp[0][n]))

if __name__ == '__main__':
    main()