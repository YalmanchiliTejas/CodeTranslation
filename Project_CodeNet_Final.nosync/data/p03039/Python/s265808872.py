import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())

N,M,K = MI()
mod = 10**9+7


def kaijou(n):
    res = 1
    for i in range(1,n+1):
        res *= i
        res %= mod
    return res

def nCr(n,r):
    return (kaijou(n)*pow(kaijou(r),mod-2,mod)*pow(kaijou(n-r),mod-2,mod)) % mod


a = N*(N+1)*(N-1)//6 * M**2 + M*(M+1)*(M-1)//6 * N**2
a %= mod
print((nCr(N*M-2,K-2) * a) % mod)
