import sys
import math
import itertools
import statistics
n,m=map(int,input().split())
side=[]
for _ in range(m):
    side.append(tuple(map(int,input().split())))
per_lis =[i for i in list(itertools.permutations(list(range(1,n+1)))) if i[0]==1]
ans=0
for one_case in per_lis:
    tmp=0
    for i in range(n-1):
        if ((one_case[i],one_case[i+1]) in side) or ((one_case[i+1],one_case[i]) in side):
            tmp+=1
    if tmp==n-1:
        ans+=1
print(ans)

