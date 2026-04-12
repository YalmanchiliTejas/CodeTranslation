class BIT:
    def __init__(self, N):
        self.size = N
        self.tree = [0] * (N + 1)

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

    def bisect(self, i):
        l, r = 0, i
        s = self.sum(r)
        if s == 0:
            return 0
        while r - l > 1:
            m = (r + l) // 2
            if self.sum(m) < s:
                l = m
            else:
                r = m
        return l + 1


N, *A = map(int, open(0).read().split())

memo = {a: i for i, a in enumerate(sorted(set(A)), 1)}
B = [memo[a] for a in A]
M = len(memo) + 10

bit = BIT(M)
for b in B:
    i = bit.bisect(b - 1)
    if i != 0:
        bit.add(i, -1)
    bit.add(b, 1)

print(bit.sum(M))