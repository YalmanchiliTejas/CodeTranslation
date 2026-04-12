import itertools
import numpy as np


n,m = map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(m)]
ls = list(itertools.permutations(range(1,n+1)))

count=0
for route in ls:
    if route[0]!=1:
        break

    flag = True
    for i in range(n-1):
        if ( ([route[i],route[i+1]] in ab) or ([route[i+1],route[i]] in ab) )  == False:
            flag = False
            continue
    if flag == False:
        continue
    count +=1

print(count)
