def f(ks, d):
    md = 10 ** 9 + 7
    dp = [0] * d
    just = 0

    for k in ks:
        ndp = [0] * d

        ndp[0] = s = sum(dp[i % d] for i in range(-9, 1))
        for i in range(1, d):
            ndp[i] = s = (s + dp[i % d] - dp[(i - 10) % d]) % md

        for ndi in range(just, just + k):
            ndp[ndi % d] += 1

        just = (just + k) % d
        dp = ndp

    print((dp[0] + (just == 0) - 1) % md)


ks = list(map(int, list(input())))
d = int(input())
f(ks, d)
