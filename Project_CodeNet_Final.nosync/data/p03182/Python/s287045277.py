# from https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0106_educational_dp_4
import sys
 
class LazySegmentTree:
    def __init__(self,n):
        n2=1<<n.bit_length()
        self.n=n2
        self.offset=n2
        self.data=[0]*(n2<<1)
        self.lazy=[0]*(n2<<1)
 
        update_base=[0]*n
        propagate_indices=[[] for _ in [0]*n]
        update_indices=[[] for _ in [0]*n]
        for i in range(n):
            j=i+n2+1
            b=(j>>(-j&j).bit_length()-1)-1
            update_base[i]=b
            while b>1:
                b>>=1
                propagate_indices[i].append(b)
        for i in range(n):
            k=i+1
            while k:
                update_indices[i].append(update_base[k-1])
                k-=-k&k
        self.propagate_indices=propagate_indices
        self.update_indices=update_indices
 
    def _push(self,k):
        for i in reversed(self.propagate_indices[k]):
            v=self.lazy[i]
            if v==0:
                continue
            j=i<<1
            self.data[j]+=v
            self.data[j+1]+=v
            self.lazy[j]+=v
            self.lazy[j+1]+=v
            self.lazy[i]=0
 
    def add(self,k,x):
        for i in self.update_indices[k]:
            self.data[i]+=x
            self.lazy[i]+=x
        for i in self.propagate_indices[k]:
            self.data[i]=max(self.data[i*2],self.data[i*2+1])+self.lazy[i]
 
    def get(self,k):
        self._push(k)
        ret=max(map(self.data.__getitem__, self.update_indices[k]))
        i=k+self.offset+1
        self.data[i]+=ret
        tmp=self.data[i]
        while i>1:
            parent=i>>1
            sibling=i^1
            tmp=self.data[parent]=max(tmp, self.data[sibling])+self.lazy[parent]
            i=parent
        return ret
 
 
 
 
n,m=map(int,input().split())
range_ls=[0 for _ in [0]*n]
range_rs=[[] for _ in [0]*n]
 
for line in sys.stdin.readlines():
    l,r,a=map(int, line.split())
    range_ls[l-1]+=a
    range_rs[r-1].append((l-1,a))
 
lst=LazySegmentTree(n)
ans=0
 
for i, (la,rs) in enumerate(zip(range_ls,range_rs)):
    if la!=0:
        lst.add(i,la)
    ans=max(ans,lst.get(i))
    for l,a in rs:
        lst.add(l,-a)
print(ans)
 