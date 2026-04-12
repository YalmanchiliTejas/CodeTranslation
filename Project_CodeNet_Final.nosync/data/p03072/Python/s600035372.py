# -*- coding: utf-8 -*-
N=int(input())
H=list(map(int,input().split()))
hightest=H[0]
count=1
for i in range(1,N):
    if H[i]>=hightest:
        hightest=H[i]
        count=count+1
print(count)