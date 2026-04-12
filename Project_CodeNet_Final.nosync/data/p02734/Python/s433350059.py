# https://atcoder.jp/contests/abc159/submissions/11139734

def main():
    MOD = 998244353

    N, S = map(int, input().split())
    *a, = map(int, input().split())

    dp = [0] * (S + 1)

    ret = 0
    for i, x in enumerate(a):
        dp[0] += 1
        if x > S: continue
        ret = (ret + dp[S - x] * (N - i)) % MOD
        for k in range(S - 1, x - 1, -1):
            dp[k] = (dp[k] + dp[k - x]) % MOD

    print(ret)


if __name__ == '__main__':
    main()
