import sys
#import math
#import numpy as np
'''a,b= map(int,input().split())'''
#a, b, c = [list(map(int, input().split())) for _ in range(3)]
#li0= [int(x) for x in input().split()]
#n,l= map(int, input().split())
#x = [list(map(int, input().split())) for _ in range(n)] 
N=str(input())
li=list(N)
i=0
for i in range(2):
  if(li[i]!=li[i+1]):
    print('Yes')
    sys.exit()
print('No')