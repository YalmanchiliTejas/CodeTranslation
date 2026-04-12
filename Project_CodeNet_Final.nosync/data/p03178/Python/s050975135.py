mod = 10 ** 9 + 7

K = map(int, input())
D = int(input())

s = 0
dp = [0] * D
for k in K:
    ndp = [0] * D
    for d in range(10):
        for i, dpi in enumerate(dp, d):
            ndp[i % D] += dpi

    for d in range(s, s + k):
        ndp[d % D] += 1

    s = (s + k) % D
    dp = [x % mod for x in ndp]

print((dp[0] - (s != 0)) % mod)