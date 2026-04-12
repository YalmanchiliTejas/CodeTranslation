def f(ks, d):
    md = 10 ** 9 + 7
    dp = [0] * d
    just = 0

    for k in ks:
        ndp = [0] * d

        for di, dk in enumerate(dp):
            for ndi in range(di, di + 10):
                ndp[ndi % d] += dk

        for ndi in range(just, just + k):
            ndp[ndi % d] += 1

        ndp = [ndk % md for ndk in ndp]

        just = (just + k) % d
        dp = ndp

    print((dp[0] + (just == 0) - 1) % md)


ks = list(map(int, list(input())))
d = int(input())
f(ks, d)
