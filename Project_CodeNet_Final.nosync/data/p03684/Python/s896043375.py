class UnionFind():
    n=1
    par=[0]
    rnk=[0]
    def __init__(self,size):
        self.n=size
        self.par=[i for i in range(self.n)]
        self.rnk=[0 for i in range(self.n)]
    def find(self,vertex1):
        if self.par[vertex1]==vertex1:
            return vertex1
        else:
            self.par[vertex1]=self.find(self.par[vertex1])
            return self.par[vertex1]
    def unite(self,vertex1,vertex2):
        vertex1=self.find(vertex1)
        vertex2=self.find(vertex2)
        if vertex1==vertex2:
            return
        if (self.rnk[vertex1]<self.rnk[vertex2]):
            self.par[vertex1]=vertex2
        else:
            self.par[vertex2]=vertex1
            if(self.rnk[vertex1]==self.rnk[vertex2]):
                self.rnk[vertex1]+=1
    def same(self,vetrex1,vertex2):
        return self.find(vetrex1)==self.find(vertex2)

N=int(input())
edge=[]
points=[]
for i in range(N):
    x,y=map(int,input().split())
    points.append((i,x,y))
points.sort(key=lambda x:x[1])
for i in range(N-1):
    i1,x1,y1=points[i]
    i2,x2,y2=points[i+1]
    wt=min(abs(x1-x2),abs(y1-y2))
    edge.append((wt,i1,i2))
points.sort(key=lambda x:x[2])
for i in range(N-1):
    i1,x1,y1=points[i]
    i2,x2,y2=points[i+1]
    wt=min(abs(x1-x2),abs(y1-y2))
    edge.append((wt,i1,i2))
edge.sort()
G=UnionFind(N)
ans=0
for e in edge:
    w,i,j=e
    if not(G.same(i,j)):
        G.unite(i,j)
        ans+=w
print(ans)