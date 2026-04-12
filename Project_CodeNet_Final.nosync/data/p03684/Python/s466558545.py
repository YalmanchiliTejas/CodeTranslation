# -*- coding: utf-8 -*-
#import heapq


N = int(input())

Xs = []
Ys = []

V = [] #辺を格納

for i in range(N):
    x, y = map(int, input().split())
    Xs.append((x,i))
    Ys.append((y,i))

Xs.sort()
Ys.sort()
# print(Xs)
# print(Ys)
Xedges = []
Yedges = []
for i in range(N-1):
    Xedges.append((Xs[i+1][0]-Xs[i][0],Xs[i][1],Xs[i+1][1]))
    Yedges.append((Ys[i+1][0]-Ys[i][0],Ys[i][1],Ys[i+1][1]))
Xedges.extend(Yedges)
Xedges.sort()

# print(Xedges)
# print(Yedges)


class UnionFind:
    def __init__(self, size):
        # 負の値はルート (集合の代表) で集合の個数
        # 正の値は次の要素を表す
        self.table = [-1 for _ in range(size)]

    # 集合の代表を求める
    def find(self, x):
        if self.table[x] < 0:
            return x
        else:
            # 経路の圧縮
            self.table[x] = self.find(self.table[x])
            return self.table[x]

    # 併合
    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] <= self.table[s2]:
                # 小さいほうが個数が多い
                self.table[s1] += self.table[s2]
                self.table[s2] = s1
            else:
                self.table[s2] += self.table[s1]
                self.table[s1] = s2
            return True
        return False

    # 部分集合とその要素数を返す
    def subsetall(self):
        a = []
        for i in range(len(self.table)):
            if self.table[i] < 0:
                a.append((i, -self.table[i]))
        return a

uf = UnionFind(N)

# クラスカルのアルゴリズムを用いる
# 閉路を作らないように値が小さい辺から順々に足していく
i = 0
while len(V) != N-1:
    v, x1, x2 = Xedges[i]
    if uf.find(x1) != uf.find(x2):
        uf.union(x1, x2)
        V.append(v)
        # print(v, x1, x2)
    i += 1
# print(V)
print(sum(V))
