# -*- coding: utf-8 -*- 
input()
monts=map(int,input().split())
highest=0
count=0
for mont in monts:
    if mont>=highest:
        highest=mont
        count+=1
print(count)