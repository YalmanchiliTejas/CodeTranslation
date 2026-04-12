N, A, B, C, D = map(int, raw_input().split())
mod = 10 ** 9 + 7

# 階乗 & 逆元計算
factorial = [1]
inverse = [1]
for i in xrange(1, N + 2):
    factorial.append(factorial[-1] * i % mod)
    inverse.append(pow(factorial[-1], mod - 2, mod))


# 組み合わせ計算
def nCr(n, r):
    if n < r or r < 0:
        return 0
    elif r == 0:
        return 1
    return factorial[n] * inverse[r] * inverse[n - r] % mod


# n人いたときに、k人組を、x個つくる場合の数
def f(n, k, x):
    return nCr(n, k * x) * factorial[k * x] * pow(pow(factorial[k], x, mod), mod-2, mod) * inverse[x] % mod


dp = [0] * (N + 1)
dp[0] = 1

for k in xrange(A, B + 1):  # k人からなるグループをこれから作りますよ
    for n in range(1, N + 1)[::-1]:  # すでにn人は使っちゃってますよ
        X = xrange(C, D + 1)
        for x in X:
            if n - k * x < 0:  # はみ出る段階で打ち切りますよ
                break
            dp[n] += f(n, k, x) * dp[n - k * x] % mod

print(dp[N] % mod)
