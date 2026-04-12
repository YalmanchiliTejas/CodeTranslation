import sys
## io ##
def IS(): return sys.stdin.readline().rstrip()
def II(): return int(IS())
def MII(): return list(map(int, IS().split()))
def MIIZ(): return list(map(lambda x: x-1, MII()))
from itertools import accumulate as acc
MOD=10**9+7
#======================================================#
def main():
    n = II()
    aa = MII()
    aa_cum = list(acc(aa))
    ans = 0
    for i in range(n):
        mul = aa_cum[-1] - aa_cum[i]
        ans += (aa[i]*mul)%MOD
    print(ans%MOD)


if __name__ == '__main__':
    main()