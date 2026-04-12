N=int(input())
o=0
from heapq import heappop,heappush
q=[]
for a in map(int,input().split()):
    heappush(q,-a)
while -q[0]+o>=N:
    a=heappop(q)
    x,y=(-a+o)//N,(-a+o)%N
    o+=x
    heappush(q,-y+o)
print(o)