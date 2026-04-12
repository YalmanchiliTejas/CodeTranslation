from bisect import bisect_left
from collections import deque
N=int(input())
A=[int(input()) for i in range(N)]

ans=1
data=deque([A[0]])
for i in range(1,N):
    a=A[i]
    b=bisect_left(data,a)
    if b==0:
        data.appendleft(a)
        ans+=1
    else:
        data[b-1]=a

print(ans)