import sys
input = sys.stdin.readline


class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * (n + 1)
    def ope(self, x, y):
        return x + y
    def update(self, i, v):
        while i <= self.n:
            self.data[i] = self.ope(self.data[i], v)
            i += i & -i
    def query(self, i):
        ret = 0
        while 0 < i:
            ret = self.ope(self.data[i], ret)
            i &= i - 1
        return ret
    def lower(self, w):
        if w <= 0:
            return 0
        x = 0
        k = 2**(self.n.bit_length())
        while k:
            if x + k <= self.n and  self.data[x+k] < w:
                w -= self.data[x+k]
                x += k
            k >>= 1
        return x + 1



n = int(input())
a = [int(input()) for i in range(n)]
b = sorted(list(set(a)))
d = {}
for i, j in enumerate(b):
    d[j] = i
a = [d[i] for i in a]
k = len(d)

B = BIT(k)
ans = 0
for i in a:
    i = i+1
    q = B.query(i)
    if q == 0:
        B.update(i, 1)
        ans += 1
    else:
        v = B.lower(q)
        if v != i:
            B.update(v, -1)
            B.update(i, 1)
        else:
            w = B.query(i-1)
            if w == 0:
                B.update(i, 1)
                ans += 1
            else:
                v = B.lower(w)
                B.update(v, -1)
                B.update(i, 1)
print(ans)
