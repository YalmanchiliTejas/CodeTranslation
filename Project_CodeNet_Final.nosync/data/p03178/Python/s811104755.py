def solve():
    MOD = 10**9 + 7

    strN = input().rstrip()
    D = int(input())

    maxD = len(strN)

    dpLt = [0] * D
    NmodD = 0
    for d, Nd in enumerate(strN):
        Nd = int(Nd)
        dpLt2 = [0] * D
        for modD in range(D):
            dpLt[modD] = dpNow = dpLt[modD] % MOD
            for x in range(10):
                modD2 = (modD+x) % D
                dpLt2[modD2] += dpNow
        for x in range(Nd):
            modD2 = (NmodD+x) % D
            dpLt2[modD2] += 1
        NmodD = (NmodD+Nd) % D
        dpLt = dpLt2

    print((dpLt[0] + (NmodD == 0) - 1) % MOD)


solve()
