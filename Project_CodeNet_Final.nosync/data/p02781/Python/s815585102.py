from math import factorial


def nCr(n, r):
    if r <= 0:
        return 0

    if n >= r:
        return factorial(n) // (factorial(n - r) * factorial(r))
    else:
        return 0

N = input()
K = int(input())

def rec(n, k, smaller):
    n = n.lstrip('0')

    if k == 0:
        return 1

    if len(n) < k:
        return 0

    if k == 1:
        if len(n) == 1:
            return int(n)


    if smaller:
        return nCr(len(n), k) * 9 ** k


    ret = 0
    ret += rec(n[1:], k-1, False)
    ret += rec('9'*(len(n)-1), k-1, True) * (int(n[0]) - 1)
    ret += rec('9'*(len(n)-1), k, True)

    return ret
    
ans = rec(N, K, False)
print(ans)

