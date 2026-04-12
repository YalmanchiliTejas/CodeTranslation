# input = sys.stdin.readline
from bisect import *
from collections import *
from heapq import *

N,M=map(int,input().split())
AB=[list(map(int,input().split())) for i in range(M)]
data=[[] for i in range(N+1)]
for a,b in AB:
    data[a].append(b)
    data[b].append(a)

count=0
stack=[[1,set([1])]]
while stack:
    point,visited=stack.pop()
    for p in data[point]:
        if not p in visited:
            if len(visited)+1==N:
                count+=1

            else:
                a=set(list(visited))
                a.add(p)
                stack.append([p,a])
print(count)
