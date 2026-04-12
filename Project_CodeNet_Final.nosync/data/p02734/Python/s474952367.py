import sys
MOD = 998244353
def main():
    input = sys.stdin.readline
    N, S = map(int, input().split())
    *A, = map(int, input().split())
    A = [0] + A
    dp = [[0] * 3 for __ in range(S + 5)]
    dp[0][0] = 1
    for i in range(1, N + 1):
        for s in range(S, -1, -1):
            ps = s - A[i]
            dp[s][1] = (dp[s][1] + dp[s][0]) % MOD
            dp[s][2] = (dp[s][2] + dp[s][0]) % MOD
            dp[s][2] = (dp[s][2] + dp[s][1]) % MOD
            if ps >= 0:
                dp[s][1] = (dp[s][1] + dp[ps][0]) % MOD
                dp[s][1] = (dp[s][1] + dp[ps][1]) % MOD
                dp[s][2] = (dp[s][2] + dp[ps][0]) % MOD
                dp[s][2] = (dp[s][2] + dp[ps][1]) % MOD

    print(dp[S][2])

if __name__ == '__main__':
    main()
