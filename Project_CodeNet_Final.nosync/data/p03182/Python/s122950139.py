import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

class RAQ_RMQ:
    def __init__(self, n, F=min, e=float("inf")):
        self.n = n
        self.n0 = 2**(n-1).bit_length()
        self.e = e
        self.F = F
        self.lazy = [0]*(2*self.n0)
        self.data = [e]*(2*self.n0)

    def construct(self, a):
        for i, x in enumerate(a):
            self.data[i+self.n0] = x
        for i in range(self.n0-1, 0, -1):
            self.data[i] = self.F(self.data[2*i], self.data[2*i+1])

    def bottomup(self, i):
        i += self.n0
        k = i//(i & -i)
        c = k.bit_length()
        for j in range(c-1):
            k >>= 1
            self.data[k] = self.F(self.data[2*k], self.data[2*k+1]) + self.lazy[k]

    def topdown(self, i):
        i += self.n0
        k = i//(i & -i)
        c = k.bit_length()
        for j in range(c-1):
            idx = k >> (c - j - 1)
            ax = self.lazy[idx]
            if not ax:
                continue
            self.lazy[idx] = 0
            self.data[2*idx] += ax
            self.data[2*idx+1] += ax
            self.lazy[2*idx] += ax
            self.lazy[2*idx+1] += ax

    def query(self, l, r):
        self.topdown(l)
        self.topdown(r)
        L = l+self.n0
        R = r+self.n0

        s = -float("inf")
        while L < R:
            if R & 1:
                R -= 1
                s = self.F(s, self.data[R])
            if L & 1:
                s = self.F(s, self.data[L])
                L += 1
            L >>= 1
            R >>= 1
        return s

    def add(self, l, r, x):
        L = l+self.n0
        R = r+self.n0

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

        self.bottomup(l)
        self.bottomup(r)

n,m = map(int, input().split())
memo = [[] for i in range(n+2)]
for i in range(m):
    l,r,a = map(int, input().split())
    memo[l].append((l,a))
    memo[r+1].append((l,-a))

seg = RAQ_RMQ(n+2, F=max, e=0)
for i in range(1, n+2):
    for j, a in memo[i]:
        seg.add(0, j, a)
    tmp = seg.query(0, i)
    seg.add(i, i+1, tmp)
ans = seg.query(0, n+1)
print(ans)