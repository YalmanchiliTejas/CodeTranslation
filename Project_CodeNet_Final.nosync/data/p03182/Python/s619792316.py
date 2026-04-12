import sys


class LazySegmentTree:
    """ [0, k) Add, [0, k) Max """

    # For speeding up index calculation, [data] [lazy] are implemented 1-rooted
    # but 'update' and 'get' query requires 0-indexed

    def __init__(self, n):
        n2 = 1 << n.bit_length()
        self.n = n2
        self.offset = n2
        self.data = [0] * (n2 << 1)
        self.lazy = [0] * (n2 << 1)

        update_base = [0] * n
        propagate_indices = [[] for _ in [0] * n]
        update_indices = [[] for _ in [0] * n]
        for i in range(n):
            j = i + n2 + 1
            b = (j >> (j & -j).bit_length() - 1) - 1
            update_base[i] = b
            while b > 1:
                b >>= 1
                propagate_indices[i].append(b)
        for i in range(n):
            k = i + 1
            while k:
                update_indices[i].append(update_base[k - 1])
                k -= k & -k
        self.propagate_indices = propagate_indices
        self.update_indices = update_indices
        # print(update_base)
        # print(propagate_indices)
        # print(update_indices)

    def _push(self, k):
        # print('push', 'k:', k, list(reversed(self.propagate_indices[k])))
        for i in reversed(self.propagate_indices[k]):
            v = self.lazy[i]
            if v == 0:
                continue
            j = i << 1
            self.data[j] += v
            self.data[j + 1] += v
            self.lazy[j] += v
            self.lazy[j + 1] += v
            self.lazy[i] = 0

    # [0, k)
    def add(self, k, x):
        # print('add', 'k:', k, 'x:', x, self.update_indices[k])
        for i in self.update_indices[k]:
            self.data[i] += x
            self.lazy[i] += x

        for i in self.propagate_indices[k]:
            self.data[i] = max(self.data[i * 2], self.data[i * 2 + 1]) + self.lazy[i]

    # [0, k)
    def get(self, k):
        self._push(k)

        # print('get', 'k:', k, self.update_indices[k])

        ret = max(map(self.data.__getitem__, self.update_indices[k]))
        # print('ret', ret)

        # This addition is specific for the problem.
        i = k + self.offset + 1
        self.data[i] += ret

        tmp = self.data[i]
        while i > 1:
            parent = i >> 1
            sibling = i ^ 1
            tmp = self.data[parent] = max(tmp, self.data[sibling]) + self.lazy[parent]
            i = parent

        return ret

    def _debug_print(self, data):
        a = 1
        while a <= self.offset:
            b = a << 1
            print('   ', data[a:b])
            a = b

    def debug_print(self):
        print('   data')
        self._debug_print(self.data)
        print('   lazy')
        self._debug_print(self.lazy)


n, m = map(int, input().split())
range_ls = [0 for _ in [0] * n]
range_rs = [[] for _ in [0] * n]
for line in sys.stdin.readlines():
    l, r, a = map(int, line.split())
    range_ls[l - 1] += a
    range_rs[r - 1].append((l - 1, a))

lst = LazySegmentTree(n)

ans = 0
for i, (la, rs) in enumerate(zip(range_ls, range_rs)):
    if la != 0:
        lst.add(i, la)
    ans = max(ans, lst.get(i))
    # print('  GET')
    # lst.debug_print()
    for l, a in rs:
        lst.add(l, -a)
    # print('  DEL')
    # lst.debug_print()
print(ans)
