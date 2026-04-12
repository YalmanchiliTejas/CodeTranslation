class UnionFind:
    def __init__(self,size):
        self.parent=range(size)
        self.tree_num=size
        self.tree_w=[1]*size
        self.rank=[0]*size

    def findset(self,x):
        if self.parent[x]==x:
            return x
        else:
            self.parent[x]=self.findset(self.parent[x])
            return self.parent[x]

    def unite(self,x,y):
        x=self.findset(x)
        y=self.findset(y)
        if x==y:
            return
        if self.rank[x]<self.rank[y]:
            self.parent[x]=y
            self.tree_num-=1
            self.tree_w[y]+=self.tree_w[x]
        else:
            self.parent[y]=x
            self.tree_num-=1
            self.tree_w[x]+=self.tree_w[y]
            if self.rank[x]==self.rank[y]:
                self.rank[x]+=1

    def same(self,x,y):
        if self.findset(x)==self.findset(y):
            return True
        else:
            return False

    def tree_number(self):
        return self.tree_num

    def tree_weight(self,x):
        return self.tree_w[self.findset(x)]
n=int(raw_input())
xy=[]
yx=[]
for i in xrange(n):
    x, y = map(int,raw_input().split())
    xy.append([x,y,i])
    yx.append([y,x,i])
xy.sort()
yx.sort()
dist=[]
for i in xrange(n-1):
    a,b,idx1=xy[i]
    c,d,idx2=xy[i+1]
    dist.append([min(abs(a-c),abs(b-d)),idx1,idx2])
for i in xrange(n-1):
    a,b,idx1=yx[i]
    c,d,idx2=yx[i+1]
    dist.append([min(abs(a-c),abs(b-d)),idx1,idx2])
dist.sort()
uf=UnionFind(n)
ans=0
for i in xrange(2*(n-1)):
    d,idx1,idx2=dist[i]
    if uf.same(idx1,idx2):continue
    uf.unite(idx1,idx2)
    ans+=d
print ans
