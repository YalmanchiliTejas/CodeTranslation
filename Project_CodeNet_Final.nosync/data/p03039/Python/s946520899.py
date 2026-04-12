#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n,m,k = map(int,input().split())
nm = n*m
class InverseTable:
    __slots__ = ['In', 'fac', 'Ifac']

    def __init__(self, mod, maxnum):
        self.In = [0, 1]; self.fac = [1, 1]; self.Ifac = [1, 1]
        for i in range( 2, maxnum + 1 ):
            self.In.append( ( -self.In[mod % i] * (mod//i) ) % mod )
            self.fac.append( ( self.fac[-1] * i ) % mod )
            self.Ifac.append( (self.Ifac[-1] * self.In[-1]) % mod )
        
    def cmb(self, n, r):
        if ( r<0 or r>n ): return 0
        r = min(r, n-r)
        return self.fac[n] * self.Ifac[r] * self.Ifac[n-r] % mod
    
    def per(self, n, r):
        if ( r<0 or r>n ): return 0
        return self.fac[n] * self.Ifac[n-r] % mod

invt = InverseTable(mod, 10**6)
# maxnum=10**6だとテーブル生成に200ms程かかるので（Pythonだと1000msほど）
# 最大生成領域は問題ごとに要検討
for i in range(n):
  for j in range(m):
    # print(i,j,(i * (i+1) // 2 + (n-1-i) * (n-i) //2 + j * (j+1) // 2 + (m-1-j) * (m-j) //2) * invt.cmb(nm-2,k-2))
    ans += ((i * (i+1) // 2 + (n-1-i) * (n-i) //2) * m + (j * (j+1) // 2 + (m-1-j) * (m-j) //2) * n) * invt.cmb(nm-2,k-2)
    ans %= mod
print(ans*pow(2,mod-2,mod)%mod)