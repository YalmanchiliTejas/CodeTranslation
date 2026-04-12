import bisect
import sys
input=sys.stdin.readline
from collections import deque
N=int(input())

cnt=0
L=[]
for i in range(N):
    n=int(input())
    L.append(n)
#print(L)
Q=[-1,10**10]
Q=deque()
#Q.appendleft(10**10)
#print(Q)
for i in range(N):
    if bisect.bisect_left(Q,L[i])==0:
        Q.appendleft(L[i])
    #elif bisect.bisect_left(Q,L[i])==len(Q)-1:
        #Q.insert(len(Q)-1,L[i])
    else:
        Q[bisect.bisect_left(Q,L[i])-1]=L[i]
#print(Q)
print(len(Q))