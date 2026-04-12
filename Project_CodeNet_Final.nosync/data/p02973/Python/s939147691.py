from collections import deque
from bisect import bisect_left
N=int(input())
li=[]
ans=0
for i in range(N):
    a=-int(input())
    b=bisect_left(li,a+1)
    if b==len(li):
        li.append(a)
        ans+=1
    else:
        li[b]=a
print(ans)