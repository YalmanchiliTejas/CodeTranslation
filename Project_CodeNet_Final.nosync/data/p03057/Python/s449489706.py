def solve(n, m, s):
    f = s[0]
    MOD = 10 ** 9 + 7
    INF = 10 ** 6

    p = None
    seq = 0
    min_seq = INF
    for c in s:
        if c == p:
            seq += 1
        else:
            if p == f and (min_seq == INF or seq % 2 == 1):
                min_seq = min(min_seq, seq)
            seq = 1
            p = c

    if min_seq == INF:
        a, b = 1, 0
        for _ in range(n - 2):
            a, b = (a + b) % MOD, a
        return (3 * a + b) % MOD

    if n % 2 == 1:
        return 0

    n2 = n // 2
    ms = min(n2, min_seq // 2 + 1)

    dp = [0] * (n2 + 1)
    dp[0] = 1
    acc, reject = 1, 0
    for i in range(1, n2 + 1):
        dp[i] = (acc - reject) % MOD
        acc = (acc + dp[i]) % MOD
        if i >= ms:
            reject = (reject + dp[i - ms]) % MOD

    ans = 0
    for d in range(1, ms + 1):
        ans = (ans + dp[n2 - d] * d * 2) % MOD

    return ans


n, m = map(int, input().split())
s = input()

print(solve(n, m, s))
