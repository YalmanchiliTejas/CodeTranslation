def main():
    n,s = map(int,input().split())
    A = list(map(int,input().split()))
    dp = [[0 for j in range(s+1)] for i in range(n+1)]

    mod = 998244353

    ans = 0

    dp[0][0] = 1

    for i in range(n):
        dp[i+1][0] = dp[i][0]+1
        for j in range(1,s+1):
            if j-A[i] >= 0:
                dp[i+1][j] += dp[i][j-A[i]]
            dp[i+1][j] = (dp[i][j]+dp[i+1][j])%mod

        ans = (ans+dp[i+1][-1])%mod
    
    print(ans%mod)
if __name__ == "__main__":
    main()
