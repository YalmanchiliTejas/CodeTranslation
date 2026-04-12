def main():
    MOD = 998244353
    N, S = map(int, input().split())
    A = list(map(int, input().split()))
    dp = [0] * (S + 1)
    ans = 0
    for i in range(N):
        dp[0] += 1
        dp2 = [0] * (S + 1)
        for j in range(S+1):
            dp2[j] += dp[j]
            if j + A[i] <= S:
                dp2[j + A[i]] += dp[j] 
                dp2[j + A[i]] %= MOD

        dp = dp2

        ans += dp[S]
        ans %= MOD

    
    print(ans)


if __name__ == "__main__":
    main()