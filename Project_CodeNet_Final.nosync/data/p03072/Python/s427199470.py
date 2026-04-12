# -*- coding: utf-8 -*-

N=int(input())
H=list(map(int,input().split()))

count=[0]*N
count[0]=1

for ii in range(1,N):
    if H[ii] >= max(H[:ii]):
        count[ii]=1
    else:
        count[ii]=0
    
print(sum(count))
