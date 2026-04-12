import sys
from collections import *
import heapq
import math
import bisect
from itertools import permutations,accumulate,combinations,product
from fractions import gcd
def input():
    return sys.stdin.readline()[:-1]
def ruiseki(lst):
    return [0]+list(accumulate(lst))
mod=pow(10,9)+7
al=[chr(ord('a') + i) for i in range(26)]

n,m=map(int,input().split())
ab=[list(map(int,input().split())) for i in range(m)]

dic=defaultdict(list)
for i in range(m):
    a,b=ab[i]
    dic[a-1].append(b-1)
    dic[b-1].append(a-1)
# print(dic)

d=deque([[0,0]])

ans=0
while d:
    now,itta=d.popleft()
    ikeru=dic[now]
    itta+=pow(2,now)
    # print(ans,now,itta)
    if itta==pow(2,n)-1:
        ans+=1
    for i in ikeru:
        if itta&pow(2,i)==0:
            d.append([i,itta])
            # print(d)
print(ans)