S = input().strip()
K = int(input())
N = len(S)
def cmb(n, r):
    nn = n
    rrr = r
    rr = 1
    for i in range(r):
        rr *= n
        n -= 1
    for i in range(r):
        rr //= r
        r -= 1
#    print(nn, rrr, rr)
    return rr

d = dict()
def f(k, i):
    if (k, i) in d:
        return d[(k, i)]
    if i == N:
        if k==0:
            return 1
        else:
            return 0
    dd = int(S[i])
    if k!=0:
        if dd == 0:
            rn = 0
            rm = 0
            r0 = f(k, i+1)
        else:
            rn = (dd-1)*cmb(N-i-1, k-1)*(9**(k-1))
            rm = f(k-1, i+1)
            r0 = cmb(N-i-1, k)*(9**k)
    else:
        rn = 0
        rm = 0
        r0 = f(k, i+1)
    d[(k,i)] = rm+rn+r0
#    print(k,i,rm,rn,r0)
    return rm + rn + r0

print(f(K, 0))
