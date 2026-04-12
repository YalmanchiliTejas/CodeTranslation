import sys
input = sys.stdin.readline
from collections import *

class Unionfind:
    def __init__(self, n):
        self.par = [-1]*n
        self.rank = [1]*n
    
    def root(self, x):
        r = x
        
        while not self.par[r]<0:
            r = self.par[r]
        
        t = x
        
        while t!=r:
            tmp = t
            t = self.par[t]
            self.par[tmp] = r
        
        return r
    
    def unite(self, x, y):
        rx = self.root(x)
        ry = self.root(y)
        
        if rx==ry:
            return
        
        if self.rank[rx]<=self.rank[ry]:
            self.par[ry] += self.par[rx]
            self.par[rx] = ry
            
            if self.rank[rx]==self.rank[ry]:
                self.rank[ry] += 1
        else:
            self.par[rx] += self.par[ry]
            self.par[ry] = rx
    
    def is_same(self, x, y):
        return self.root(x)==self.root(y)
    
    def count(self, x):
        return -self.par[self.root(x)]

N = int(input())
xy = [(i,)+tuple(map(int, input().split())) for i in range(N)]
xy.sort(key=lambda t: t[1])
edges = []

for i in range(N-1):
    edges.append((xy[i][0], xy[i+1][0], xy[i+1][1]-xy[i][1]))

xy.sort(key=lambda t: t[2])

for i in range(N-1):
    edges.append((xy[i][0], xy[i+1][0], xy[i+1][2]-xy[i][2]))

edges.sort(key=lambda t: t[2])
uf = Unionfind(N)
ans = 0

for s, t, w in edges:
    if not uf.is_same(s, t):
        uf.unite(s, t)
        ans += w

print(ans)
