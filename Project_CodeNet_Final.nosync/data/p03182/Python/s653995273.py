class StarrySkyTree:
    def __init__(self,num):
        leaf=1<<(num-1).bit_length()
        self.leaf=leaf
        self.data=[0]*leaf*2
        self.lazy=[0]*leaf*2
    def indices(self,l,r):
        L,R=l+self.leaf,r+self.leaf
        lm=(L//(L&-L))>>1
        rm=(R//(R&-R))>>1
        while L<R:
            if R<=rm:
                yield R
            if L<=lm:
                yield L
            L>>=1; R>>=1
        while L:
            yield L
            L>>=1
    def zeroindices(self,k):
        K=k+self.leaf
        limit=(K//(K&-K))>>1
        while K:
            if K<=limit:
                yield K
            K>>=1
    def _propagates(self,*ids):
        for i in reversed(ids):
            v=self.lazy[i-1]
            if v==0:
                continue
            self.lazy[2*i-1]+=v; self.lazy[2*i]+=v
            self.data[2*i-1]+=v; self.data[2*i]+=v
            self.lazy[i-1]=0
    def add(self,l,r,x):
        L,R=l+self.leaf,r+self.leaf
        while L<R:
            if L&1:
                self.lazy[L-1]+=x; self.data[L-1]+=x
                L+=1
            if R&1:
                R-=1
                self.lazy[R-1]+=x; self.data[R-1]+=x
            L>>=1; R>>=1
        for i in self.indices(l,r):
            self.data[i-1]=max(self.data[2*i-1],self.data[2*i])+self.lazy[i-1]
    def add1(self,k,x):
        k+=self.leaf
        self.data[k-1]+=x
        while k:
            k>>=1
            self.data[k-1]=max(self.data[2*k-1],self.data[2*k])+self.lazy[k-1]
    def query0(self,k):
        self._propagates(*self.zeroindices(k))
        L,R=self.leaf,k+self.leaf
        ret=0
        while L<R:
            if L&1:
                ret=max(ret,self.data[L-1])
                L+=1
            if R&1:
                R-=1
                ret=max(ret,self.data[R-1])
            L>>=1; R>>=1
        return ret

import sys
input=sys.stdin.readline
n,m=map(int,input().split())
sst=StarrySkyTree(n+1)
R=[[] for _ in range(n+1)]
for _ in range(m):
    l,r,a=map(int,input().split())
    R[r].append((l,a))
for i in range(1,n+1):
    v=sst.query0(i)
    sst.add1(i,v)
    for l,a in R[i]:
        sst.add(l,i+1,a)
print(sst.query0(n+1))