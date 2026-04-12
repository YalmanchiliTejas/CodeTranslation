class BIT:
    def __init__(self, N):
        self.size = N
        self.tree = [0] * (N + 1)
        self.bisect_k = 1 << (N.bit_length() - 1)

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

    def __str__(self):
        return "BIT: [{}]".format(
            ", ".join(str(self.sum(i + 1) - self.sum(i))
                      for i in range(self.size))
        )

    def bisect(self, w):
        bit, N = self.tree, self.size
        i = 0
        k = self.bisect_k
        while k > 0:
            if i + k <= N and bit[i + k] < w:
                w -= bit[i + k]
                i += k
            k //= 2
        return i + 1

N, *A = map(int, open(0).read().split())

memo = {a: i for i, a in enumerate(sorted(set(A)), 1)}
B = [memo[a] for a in A]
M = len(memo) + 10

bit = BIT(M)
for b in B:
    s = bit.sum(b - 1)
    if s > 0:
        i = bit.bisect(s)
        bit.add(i, -1)
    bit.add(b, 1)

print(bit.sum(M))
