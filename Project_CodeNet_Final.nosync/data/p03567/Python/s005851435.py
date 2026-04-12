#!/usr/bin/env python3
#%% for atcoder uniittest use
import sys
input= lambda: sys.stdin.readline().rstrip()
def pin(type=int):return map(type,input().split())
def tupin(t=int):return tuple(pin(t))
#%%code
def resolve():
    S=input()
    for i in range(len(S)-1):
        if S[i]=="A" and S[i+1]=="C":
            print("Yes")
            break
    else:print("No")
#%%submit!
resolve()

