from bisect import bisect_left as bs
from collections import deque
N=int(input())
pallet=deque()
cnt=0
for _ in range(N):
    A=int(input())
    place=bs(pallet,A)
    if place==0:
        cnt+=1
        pallet.appendleft(A)
    else:
        pallet[place-1]=A
print(cnt)