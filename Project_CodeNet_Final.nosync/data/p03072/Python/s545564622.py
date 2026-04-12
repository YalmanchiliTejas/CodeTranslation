import sys
import fractions
import math
import itertools

n=input()
h=list(map(int,input().split()))
H=[]
ans=0

for i in range(len(h)):
	H.append(h[i])
	if max(H)==h[i]:
		ans+=1

print(ans)