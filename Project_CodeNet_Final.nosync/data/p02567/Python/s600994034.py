mycode = r'''
# distutils: language=c++
# cython: language_level=3, boundscheck=False, wraparound=False, cdivision=True
ctypedef long long LL
# cython: cdivision=True
from libc.stdio cimport scanf
from libcpp.vector cimport vector
ctypedef vector[LL] vec

cdef class SegmentTree():
    cdef LL num,n
    cdef vec tree

    def __init__(self,vec A):
        cdef LL n,i
        n = A.size()
        self.n = n
        self.num = 1 << (n-1).bit_length()
        self.tree = vec(2*self.num,0)
        for i in range(n):
            self.tree[self.num + i] = A[i]
        for i in range(self.num-1,0,-1):
            self.tree[i] = max(self.tree[2*i],self.tree[2*i+1])

    cdef void update(self,LL k,LL x):
        k += self.num
        self.tree[k] = x
        while k>1:
            self.tree[k>>1] = max(self.tree[k],self.tree[k^1])
            k >>= 1

    cdef LL query(self,LL l,LL r):
        cdef LL res
        res = 0
        l += self.num
        r += self.num
        while l<r:
            if l&1:
                res = max(res,self.tree[l])
                l += 1
            if r&1:
                res = max(res,self.tree[r-1])
            l >>= 1
            r >>= 1
        return res

    cdef LL bisect_l(self,LL l,LL r,LL x):
        cdef LL Lmin,Rmin,pos
        l += self.num
        r += self.num
        Lmin = -1
        Rmin = -1
        while l<r:
            if l&1:
                if self.tree[l] >= x and Lmin == -1:
                    Lmin = l
                l += 1
            if r&1:
                if self.tree[r-1] >= x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        if Lmin!=-1:
            pos = Lmin
            while pos<self.num:
                if self.tree[2*pos] >= x:
                    pos = 2*pos
                else:
                    pos = 2*pos + 1
            return pos-self.num

        elif Rmin!=-1:
            pos = Rmin
            while pos<self.num:
                if self.tree[2*pos] >= x:
                    pos = 2*pos
                else:
                    pos = 2*pos + 1
            return pos-self.num

        else:
            return self.n


cdef LL N,Q,i
cdef vec A

scanf("%lld %lld",&N,&Q)
A = vec(N,-1)
for i in range(N):
    scanf("%lld",&A[i])

cdef SegmentTree S = SegmentTree(A)
cdef LL t,x,v

for i in range(Q):
    scanf("%lld %lld %lld",&t,&x,&v)
    if t==1:
        S.update(x-1,v)
    elif t==2:
        print(S.query(x-1,v))
    else:
        print(S.bisect_l(x-1,N,v)+1)
'''
import sys
import os
if sys.argv[-1] == 'ONLINE_JUDGE':  # コンパイル時
    with open('mycode.pyx', 'w') as f:
        f.write(mycode)
    os.system('cythonize -i -3 -b mycode.pyx')

import mycode
