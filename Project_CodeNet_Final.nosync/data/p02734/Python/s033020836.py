from collections import defaultdict

MOD = 998244353


def main():
    N, S = map(int, input().split())
    A = list(map(int, input().split()))
#    dp = [defaultdict(int) for _ in range(S)]
    dp = [0] * S
    ans = 0
    for right in range(N):
        num = A[right]
        if num > S:
            continue
        elif num == S:
            ans = (ans + (right+1) * (N-right)) % MOD
            continue
        # for left in dp[S-num]:
        #     cnt = dp[S-num][left]
        #     ans = (ans + (left+1) * (N-right) * cnt) % MOD
        # for i in range(S-num-1, -1, -1):
        #     for left in dp[i]:
        #         dp[i+num][left] += dp[i][left]
        # dp[num][right] = 1
        ans = (ans + dp[S-num] * (N-right)) % MOD
        for i in range(S-num-1, -1, -1):
            dp[i+num] += dp[i]
        dp[num] += right + 1
    print(ans)


if __name__ == "__main__":
    main()
