import sys
input = sys.stdin.readline
from collections import *

def dfs(n, x):
    if n==0:
        return 1
        
    s = 2**(n+1)-3
    
    if x<=1:
        return 0
    elif x<=1+s:
        return dfs(n-1, x-1)
    elif x==2+s:
        return dfs(n-1, s)+1
    elif x<=2+2*s:
        return dfs(n-1, s)+1+dfs(n-1, x-2-s)
    else:
        return 2*dfs(n-1, s)+1

N, X = map(int, input().split())
print(dfs(N, X))