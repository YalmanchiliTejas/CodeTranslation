def comb(n, k):
    nu, de = 1, 1
    for i in range(k):
        de *= n - i
        nu *= i + 1
    return de // nu


def ans(N, K):
    if K == 0:
        return 1
    N = str(int(N))
    if len(N) < K or int(N) == 0:
        return 0
    ret = sum([9 ** K * comb(max(dig - 1, 1), K - 1)
               for dig in range(K, len(N))])
    ret += (int(N[0]) - 1) * 9 ** (K - 1) * comb(len(N) - 1, K - 1)
    return ret + ans(N[1:], K - 1)


N = input()
K = int(input())
print(ans(N, K))
