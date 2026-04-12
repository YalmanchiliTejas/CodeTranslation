class BIT:
    def __init__(self, N):
        self.size = N
        self.tree = [0] * (N + 1)
        self.MSB = 1 << (N.bit_length() - 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

    def bisect(self, w):
        bit, N = self.tree, self.size
        i = 0
        K = N.bit_length()
        for k in (1 << k for k in reversed(range(K))):
            if i + k <= N and bit[i + k] < w:
                w -= bit[i + k]
                i += k
        return i + 1

N, *A = map(int, open(0).read().split())

memo = {a: i for i, a in enumerate(sorted(set(A)), 1)}
M = len(memo)

bit = BIT(M)
for b in (memo[a] for a in A):
    s = bit.sum(b - 1)
    if s > 0:
        i = bit.bisect(s)
        bit.add(i, -1)
    bit.add(b, 1)

print(bit.sum(M))
