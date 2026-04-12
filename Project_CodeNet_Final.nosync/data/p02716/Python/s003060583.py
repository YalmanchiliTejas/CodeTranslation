def main():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [-10**15]*(n+1)
    dp[2] = max(a[0], a[1])
    if n > 2:
        dp[3] = max(a[:3])
        aa = a[0]+a[2]
        for i in range(4, n+1):
            if i%2:
                aa += a[i-1]
                dp[i] = max(dp[i-1], dp[i-2]+a[i-1])
            else:
                dp[i] = max(aa, dp[i-2]+a[i-1])
    print(dp[n])

if __name__ == "__main__":
    main()