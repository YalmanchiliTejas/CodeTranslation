import sys
input = sys.stdin.readline

class segtree:
    x_unit=0 # 単位元
    x_func=max  # 関数
    def __init__(self,n):
        self.n=n
        self.x=[self.x_unit]*(2*n)
    def build(self, seq):
        for i,j in enumerate(seq, self.n):  # n番目からseqをx配列に移していく
            self.x[i] = j
        for i in range(self.n-1, 0, -1):
            self.x[i] = self.x_func(self.x[i*2], self.x[i*2+1])
    def update(self,i,j): # 1点更新
        i += self.n
        self.x[i]=j
        while i>1:
            i//=2 # 更新後、木の上へと登っていくついでに更新
            self.x[i]=self.x_func(self.x[i*2], self.x[i*2+1])
    def fold(self,l,r): # 区間[l, r)の最小値などを取得 
        l+=self.n
        r+=self.n
        val_l=self.x_unit
        val_r=self.x_unit
        while l<r:
            if l & 1: # lが奇数
                val_l=self.x_func(val_l,self.x[l])
                l+=1 # 偶数に調節
            if r & 1: # rが奇数
                r-=1 # 開区間なので1個前は偶数番目の要素
                val_r=self.x_func(val_r,self.x[r])
            l //= 2
            r //= 2
        return self.x_func(val_l,val_r)
    def find_j(self, l, v):
        r=self.n
        if self.fold(l, r)<v:
            return r
        else:
            while r-l>1:
                l1=l
                r1=l+(r-l)//2
                l2=l+(r-l)//2
                r2=r
                if self.fold(l1, r1)>=v:
                    l=l1
                    r=r1
                else:
                    l=l2
                    r=r2
            return l

n,q=map(int,input().split()) 
seg=segtree(n)
*a,=map(int,input().split())
seg.build(a)
for i in range(q):
    t,x,y=map(int,input().split()) 
    if t==1:
        x-=1
        seg.update(x, y)
    elif t==2:
        print(seg.fold(x-1,y))
    else:
        print(seg.find_j(x-1, y)+1)

