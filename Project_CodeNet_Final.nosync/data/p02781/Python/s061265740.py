def nCk(n, k):
    if k == 0:
        return 1
    elif k == 1:
        return n
    elif k == 2:
        return n * (n - 1) // 2
    else:
        return n * (n - 1) * (n - 2) // 6


def solve(N, K):
    if N == 0 and K > 0:
        return 0

    if K == 0:
        return 1

    M = len(str(N))
    hd, tl = divmod(N, 10 ** (M - 1))

    res = nCk(M - 1, K) * (9 ** K)
    if hd == 0:
        return res

    res += solve(tl, K - 1)
    res += (hd - 1) * nCk(M - 1, K - 1) * (9 ** (K - 1))

    return res


N = int(input())
K = int(input())

print(solve(N, K))