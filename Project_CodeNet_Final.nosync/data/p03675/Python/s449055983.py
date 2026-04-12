# -*- coding: utf-8 -*-
#ARC077C
import sys
import math

n=int(input())

tmp = input().split()
hoge = list(map(lambda a: int(a), tmp))


ans=[]
if(n%2==0):
	for i in range(0,n//2):
		ans.append(hoge[n-i*2-1])
	for i in range(0,n//2):
		ans.append(hoge[i*2])
else:
	for i in range(0,n//2+1):
		ans.append(hoge[n-i*2-1])
	for i in range(0,n//2):
		ans.append(hoge[i*2+1])
	

ret=""
ret+=str(ans[0])
for i in range(1,n):
	ret+=" "
	ret+=str(ans[i])
print(ret)
