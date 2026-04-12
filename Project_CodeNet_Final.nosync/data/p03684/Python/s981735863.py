class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n)) #親ノード
        self.size = [1]*n #グループの要素数
 
    def root(self, x): #root(x): xの根ノードを返す．
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x 
 
    def merge(self, x, y): #merge(x,y): xのいる組とyのいる組をまとめる
        x, y = self.root(x), self.root(y)
        if x == y: return False
        if self.size[x] < self.size[y]: x,y=y,x #xの要素数が大きいように
        self.size[x] += self.size[y] #xの要素数を更新
        self.parent[y] = x #yをxにつなぐ
        return True
 
    def issame(self, x, y): #same(x,y): xとyが同じ組ならTrue
        return self.root(x) == self.root(y)
        
    def getsize(self,x): #size(x): xのいるグループの要素数を返す
        return self.size[self.root(x)]

# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

n,*xy = map(int,read().split())

mp = iter(xy)
xyi = [(x,y,i) for i,(x,y) in enumerate(zip(mp,mp))]

res = []

xyi.sort()
for (x,y,i),(z,w,j) in zip(xyi[1:],xyi):
    res.append((x-z,i,j))
xyi.sort(key = lambda x:x[1])
for (x,y,i),(z,w,j) in zip(xyi[1:],xyi):
    res.append((y-w,i,j))

#print(res)
res.sort()
UF = UnionFind(n)

num = 1
ans = 0
for d,i,j in res:
    if UF.merge(i,j):
        num += 1
        ans += d
    if num==n: break

print(ans)



