import math
import sys
import bisect
input=sys.stdin.readline
#t=int(input())
t=1
for _ in range(t):
    n=int(input())
    #n,k=map(int,input().split())
    #l=list(map(int,input().split()))
    if n>=30:
        print('Yes')
    else:
        print('No')