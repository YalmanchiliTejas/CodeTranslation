class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.range = [(-1,n)] * 2 * self.num
        # 配列の値を葉にセット
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
            self.range[self.num + i] = (i,i)
        # 構築していく
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])
            self.range[i] = (self.range[2 * i][0],self.range[2 * i + 1][1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = x
        while k > 1:
            self.tree[k >> 1] = self.segfunc(self.tree[k], self.tree[k ^ 1])
            k >>= 1

    def query(self, l, r):
        res = self.ide_ele

        l += self.num
        r += self.num
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                res = self.segfunc(res, self.tree[r - 1])
            l >>= 1
            r >>= 1
        return res

    def bisect_l(self,l,r,x):
        l += self.num
        r += self.num
        Lmin = -1
        Rmin = -1
        while l<r:
            if l & 1:
                if self.tree[l] >= x and Lmin==-1:
                    Lmin = l
                l += 1
            if r & 1:
                if self.tree[r-1] >=x:
                    Rmin = r-1
            l >>= 1
            r >>= 1

        if Lmin != -1:
            pos = Lmin
            while pos<self.num:
                if self.tree[2 * pos] >=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        elif Rmin != -1:
            pos = Rmin
            while pos<self.num:
                if self.tree[2 * pos] >=x:
                    pos = 2 * pos
                else:
                    pos = 2 * pos +1
            return pos-self.num
        else:
            return N

import sys

input = sys.stdin.readline

N,Q = map(int,input().split())
A = list(map(int,input().split()))

Seg = SegmentTree(A,max,0)

for _ in range(Q):
    query = list(map(int,input().split()))
    if query[0] == 1:
        gomi,idx,val = query
        Seg.update(idx-1,val)
    elif query[0] == 2:
        gomi,l,r = query
        print(Seg.query(l-1,r))
    else:
        gomi,l,val = query
        print(Seg.bisect_l(l-1,N,val)+1)