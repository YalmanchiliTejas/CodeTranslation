import sys
import math
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, input().split()))
ns = lambda: input()

N,K = na()
result=0
for b in range(1,N+1):
    p = N//b
    r = N%b
    result+=p*max(0,b-K)
    result+=max(0,r+1-K)
    if(K==0):
        result-=1

print(result)