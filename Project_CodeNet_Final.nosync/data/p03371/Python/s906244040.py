#print#!/usr/bin/env python3
#%% for atcoder uniittest use
import sys
input= lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**9)
def pin(type=int):return map(type,input().split())
def tupin(t=int):return tuple(pin(t))
def lispin(t=int):return list(pin(t))
#%%code
from collections import Counter
def resolve():
    A,B,C,X,Y=pin()
    ans=A*X+B*Y
    if X>Y:
        ans=min(ans,A*(X-Y)+2*C*Y)
        ans=min(ans,C*2*X)
    else:
        ans=min(ans,B*(Y-X)+2*C*X)
        ans=min(ans,C*2*Y)
    print(ans)
#%%submit!
resolve()