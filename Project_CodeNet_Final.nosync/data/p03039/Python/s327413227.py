mod = 1000000007
import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())


def cmb(n, r):
    if n<0 or r<0 or r>n:
        return None
    r = min(r, n-r)
    if r == 0:
        return 1
    if r == 1:
        return n
    numerator = [0]*r
    denominator = [0]*r
    for k in range(r):
        numerator[k] = n-r+k+1
        denominator[k] = k+1
    for p in range(2, r+1):
        pivot = denominator[p-1]
        if pivot > 1:
            offset = (n-r) % p
            for k in range(p-1, r, p):
                numerator[k-offset] //= pivot
                denominator[k] //= pivot
    res = 1
    for n in numerator:
        if n > 1:
            res *= n
    return res

N2 = N**2
M2 = M**2
Xpattern = [(x * (N-x)) % mod for x in range(N)]
Ypattern = [(y * (M-y)) % mod for y in range(M)]
coef = cmb(N*M-2, K-2)

print(((sum(Xpattern)*M2+sum(Ypattern)*N2)*coef)%mod)