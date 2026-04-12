N = int(input())
s = input()

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.root = [-1]*(n+1)
        self.rnk = [0]*(n+1)
        
    def find_root(self, x):
        if self.root[x] < 0:
            return x
        else:
            self.root[x] = self.find_root(self.root[x])
            return self.root[x]
        
    def unite(self, x, y):
        x = self.find_root(x)
        y = self.find_root(y)
        if x == y:
            return
        elif self.rnk[x] > self.rnk[y]:
            self.root[x] += self.root[y]
            self.root[y] = x
        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if self.rnk[x] == self.rnk[y]:
                self.rnk[y] += 1
                
    def isSameGroup(self, x, y):
        return self.find_root(x) == self.find_root(y)
    
    def count(self, x):
        return -self.root[self.find_root(x)]
    
uf0 = UnionFind(N+1) #1が羊、2が羊だとした場合のグループ分け
uf1 = UnionFind(N+1) #1が羊、2が狼だとした場合のグループ分け
uf2 = UnionFind(N+1) #1が狼、2が羊だとした場合のグループ分け
uf3 = UnionFind(N+1) #1が狼、2が狼だとした場合のグループ分け

#0は羊、N+1は狼のグループ
uf0.unite(1, 0)
uf0.unite(2, 0)
uf1.unite(1, 0)
uf1.unite(2, N+1)
uf2.unite(1, N+1)
uf2.unite(2, 0)
uf3.unite(1, N+1)
uf3.unite(1, N+1)

if s[0] == "o":
    uf0.unite(N, 0)
    uf1.unite(N, N+1)
    uf2.unite(N, N+1)
    uf3.unite(N, 0)
else:
    uf0.unite(N, N+1)
    uf1.unite(N, 0)
    uf2.unite(N, 0)
    uf3.unite(N, N+1)
    
for i in range(2, N+1):
    if i == N:
        a = 1
    else:
        a = i+1
        
    if s[i-1] == "o":
        if uf0.isSameGroup(i, 0):
            uf0.unite(i-1, a)
        elif uf0.isSameGroup(i-1, 0):
            uf0.unite(a, N+1)
        else:
            uf0.unite(a, 0)
        
        if uf1.isSameGroup(i, 0):
            uf1.unite(i-1, a)
        elif uf1.isSameGroup(i-1, 0):
            uf1.unite(a, N+1)
        else:
            uf1.unite(a, 0)
            
        if uf2.isSameGroup(i, 0):
            uf2.unite(i-1, a)
        elif uf2.isSameGroup(i-1, 0):
            uf2.unite(a, N+1)
        else:
            uf2.unite(a, 0)
            
        if uf3.isSameGroup(i, 0):
            uf3.unite(i-1, a)
        elif uf3.isSameGroup(i-1, 0):
            uf3.unite(a, N+1)
        else:
            uf3.unite(a, 0)
            
    else:
        if not uf0.isSameGroup(i, 0):
            uf0.unite(i-1, a)
        elif uf0.isSameGroup(i-1, 0):
            uf0.unite(a, N+1)
        else:
            uf0.unite(a, 0)
            
        if not uf1.isSameGroup(i, 0):
            uf1.unite(i-1, a)
        elif uf1.isSameGroup(i-1, 0):
            uf1.unite(a, N+1)
        else:
            uf1.unite(a, 0)
            
        if not uf2.isSameGroup(i, 0):
            uf2.unite(i-1, a)
        elif uf2.isSameGroup(i-1, 0):
            uf2.unite(a, N+1)
        else:
            uf2.unite(a, 0)
            
        if not uf3.isSameGroup(i, 0):
            uf3.unite(i-1, a)
        elif uf3.isSameGroup(i-1, 0):
            uf3.unite(a, N+1)
        else:
            uf3.unite(a, 0)
            
ans = -1
if not uf0.isSameGroup(0, N+1):
    ans = uf0
elif not uf1.isSameGroup(0, N+1):
    ans = uf1
elif not uf2.isSameGroup(0, N+1):
    ans = uf2
elif not uf3.isSameGroup(0, N+1):
    ans = uf3
    
if ans == -1:
    print(ans)
else:
    t = []
    for i in range(1, N+1):
        if ans.isSameGroup(i, 0):
            t.append("S")
        else:
            t.append("W")
    print("".join(t))