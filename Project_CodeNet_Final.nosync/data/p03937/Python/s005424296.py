import numpy as np
H,W=map(int, input().split())
A=[]
for i in range(H):
    a=list(input())
    A.append(a)

A=np.array(A)
ok=True
for h in range(H):
    for w in range(W):
        
        lu=0
        rd=0
        if A[h,w]=="#":
            if 0<=h-1 and h-1<H:
                if A[h-1,w]=="#":
                    lu+=1
            if 0<=w-1 and w-1<W:
                if A[h,w-1]=="#":
                    lu+=1
            if 0<=h+1 and h+1<H:
                if A[h+1,w]=="#":
                    rd+=1
            if 0<=w+1 and w+1<W:
                if A[h,w+1]=="#":
                    rd+=1
            if h==0 and w==0:
                lu=1
            if h==H-1 and w==W-1:
                rd=1
            if lu!=1 or rd!=1:
                ok=False
if ok:
    print("Possible")
else:
    print("Impossible")