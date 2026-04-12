#import sys
#import math
#import numpy as np
'''a,b= map(int,input().split())'''
#a, b, c = [list(map(int, input().split())) for _ in range(3)]
#li0= [int(x) for x in input().split()]
#n,l= map(int, input().split())
#x = [list(map(int, input().split())) for _ in range(n)] 
N=int(input())
li= [int(x) for x in input().split()]
lar=li[0]
ans=1
for i in range(1,N):
  if li[i]>=lar:
    ans+=1
    lar=li[i]
print(ans)
