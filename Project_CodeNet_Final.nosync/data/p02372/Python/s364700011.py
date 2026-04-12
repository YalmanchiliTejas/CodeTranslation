class Tree():
    def __init__(self,n,edge):
        self.n = n
        self.tree = [[] for _ in range(n)]
        for e in edge:
            self.tree[e[0]].append((e[1],e[2]))
            self.tree[e[1]].append((e[0],e[2]))
    def setroot(self,root):
        self.root = root
        self.parent = [None for _ in range(self.n)]
        self.parent[root] = -1
        self.depth = [None for _ in range(self.n)]
        self.depth[root] = 0
        self.distance = [None for _ in range(self.n)]
        self.distance[root] = 0
        stack = [root]
        while stack:
            node = stack.pop()
            for adj,cost in self.tree[node]:
                if self.parent[adj] is None:
                    self.parent[adj] = node
                    self.depth[adj] = self.depth[node]+1
                    self.distance[adj] = self.distance[node]+cost
                    stack.append(adj)
    def diam(self):
        u = self.distance.index(max(self.distance))
        dist_u = [None for _ in range(N)]
        dist_u[u] = 0
        stack = [u]
        while stack:
            node = stack.pop()
            for adj,cost in self.tree[node]:
                if dist_u[adj] is None:
                    dist_u[adj] = dist_u[node]+cost
                    stack.append(adj)
        d = max(dist_u)
        v = dist_u.index(d)
        return d,u,v
    def construct_lca(self):
        L = (self.n-1).bit_length()
        self.k_parent = [self.parent]
        prev = self.parent
        for k in range(L):
            array = [0 for _ in range(self.n)]
            for i in range(self.n):
                if prev[i] == -1: continue
                array[i] = prev[prev[i]]
            self.k_parent.append(array)
            prev = array
    def lca(self,u,v):
        d = self.depth[v]-self.depth[u]
        if d < 0: u,v,d = v,u,-d
        for k in self.k_parent:
            if d & 1: v = k[v]
            d >>= 1
        if u == v: return u
        for k in reversed(self.k_parent):
            pu,pv = k[u],k[v]
            if pu != pv: u,v = pu,pv
        return self.k_parent[0][u]
    def dist(self,u,v):
        l = self.lca(u,v)
        return self.distance[u]+self.distance[v]-2*self.distance[l]

import sys
input = sys.stdin.readline

N = int(input())
E = [tuple(map(int,input().split())) for _ in range(N-1)]

t = Tree(N,E)
t.setroot(0)
t.construct_lca()
d,u,v = t.diam()
ans = []

for i in range(N):
    ans.append(max(t.dist(i,u),t.dist(i,v)))

print('\n'.join(map(str,ans)))
