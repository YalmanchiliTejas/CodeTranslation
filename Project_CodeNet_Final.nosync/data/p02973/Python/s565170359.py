n=int(input())
A=[int(input()) for i in range(n)]
l=[-A[0],1]#-にして小さい順から並ぶようにする
from bisect import *
for a in A[1:]:
    idx=bisect_left(l,-a+1)
    p=-l[idx]
    if p==-1:
        l[-1]=-a
        l.append(1)
    else:
        l[idx]=-a
print(len(l)-1)