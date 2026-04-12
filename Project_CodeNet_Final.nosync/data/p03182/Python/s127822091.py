import sys
class Lazysegtree:
    #RAQ
    def __init__(self, A, intv, initialize = True, segf = min):
        #区間は 1-indexed で管理
        self.N = len(A)
        self.N0 = 2**(self.N-1).bit_length()
        self.intv = intv
        self.segf = segf
        self.lazy = [0]*(2*self.N0)
        if initialize:
            self.data = [intv]*self.N0 + A + [intv]*(self.N0 - self.N)
            for i in range(self.N0-1, 0, -1):
                self.data[i] = self.segf(self.data[2*i], self.data[2*i+1]) 
        else:
            self.data = [intv]*(2*self.N0)

    def _ascend(self, k):
        k = k >> 1
        c = k.bit_length()
        for j in range(c):
            idx = k >> j
            self.data[idx] = self.segf(self.data[2*idx], self.data[2*idx+1]) \
            + self.lazy[idx]
            
    def _descend(self, k):
        k = k >> 1
        idx = 1
        c = k.bit_length()
        for j in range(1, c+1):
            idx = k >> (c - j)
            ax = self.lazy[idx]
            if not ax:
                continue
            self.lazy[idx] = 0
            self.data[2*idx] += ax
            self.data[2*idx+1] += ax
            self.lazy[2*idx] += ax
            self.lazy[2*idx+1] += ax
    
    def update(self, k, x):
        k = k + self.N0
        self.data[k] = x
        self._ascend(k)
    
    def query(self, l, r):
        L = l+self.N0
        R = r+self.N0
        Li = L//(L & -L)
        Ri = R//(R & -R)
        self._descend(Li)
        self._descend(Ri - 1)
        
        s = self.intv                                                              
        while L < R:
            if R & 1:
                R -= 1
                s = self.segf(s, self.data[R])
            if L & 1:
                s = self.segf(s, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return s
    
    def add(self, l, r, x):
        L = l+self.N0
        R = r+self.N0

        Li = L//(L & -L)
        Ri = R//(R & -R)
        
        while L < R :
            if R & 1:
                R -= 1
                self.data[R] += x
                self.lazy[R] += x
            if L & 1:
                self.data[L] += x
                self.lazy[L] += x
                L += 1
            L >>= 1
            R >>= 1
        
        self._ascend(Li)
        self._ascend(Ri-1)

N, M = map(int, input().split())
LA = [[] for _ in range(N)]
for _ in range(M):
    l, r, a = map(int, sys.stdin.readline().split())
    LA[r-1].append((l-1, a))

dp = Lazysegtree([0]*(N+1), -10**16, True, max)

for i in range(N):
    res = 0
    t = dp.data[1]
    for l, a in LA[i]:
        res += a
        dp.add(l, i, a)
    dp.add(i, i+1, res + t)
print(dp.data[1])
