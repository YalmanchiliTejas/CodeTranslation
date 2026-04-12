import sys, os, math, bisect, itertools, collections, heapq, queue
from scipy.sparse.csgraph import csgraph_from_dense, floyd_warshall
from decimal import Decimal

# import fractions

sys.setrecursionlimit(10000000)

ii = lambda: int(sys.stdin.buffer.readline().rstrip())
il = lambda: list(map(int, sys.stdin.buffer.readline().split()))
fl = lambda: list(map(float, sys.stdin.buffer.readline().split()))
iln = lambda n: [int(sys.stdin.buffer.readline().rstrip()) for _ in range(n)]

iss = lambda: sys.stdin.buffer.readline().decode().rstrip()
sl = lambda: list(map(str, sys.stdin.buffer.readline().decode().split()))
isn = lambda n: [sys.stdin.buffer.readline().decode().rstrip() for _ in range(n)]

lcm = lambda x, y: (x * y) // math.gcd(x, y)
# lcm = lambda x, y: (x * y) // fractions.gcd(x, y)

MOD = 10 ** 9 + 7
MAX = float('inf')


class UnionFind:
    def __init__(self, N):
        self.tree = list(range(N))

    def root(self, N):
        if self.tree[N] == N:
            return N
        else:
            self.tree[N] = self.root(self.tree[N])
            return self.tree[N]

    def same(self, x, y):
        return self.root(self.tree[x]) == self.root(self.tree[y])

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        else:
            self.tree[x] = y


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    N = ii()
    uf = UnionFind(N)
    X, Y = [], []

    # X間とY間の距離が短い順にソート
    # 頂点の番号も保持しておく
    for n in range(N):
        x, y = il()
        X.append((x, n))
        Y.append((y, n))
    X.sort()
    Y.sort()

    # 各頂点間の重み(道を作るお金)を計算し、繋がっている頂点を保持
    # 重みでソートを行う
    dist = []
    for n in range(1, N):
        dist.append((abs(X[n][0] - X[n - 1][0]), X[n][1], X[n - 1][1]))
        dist.append((abs(Y[n][0] - Y[n - 1][0]), Y[n][1], Y[n - 1][1]))
    dist.sort()

    # クラスカル法で、重みの小さい順に辺を繋げて木とする
    # UnionFind木を用いて既に繋がっているか否かを判定し
    # 最小全域木をつくる
    ret = 0
    for d, s, u in dist:
        if not uf.same(s, u):
            ret += d
            uf.unite(s, u)
    print(ret)


if __name__ == '__main__':
    main()
