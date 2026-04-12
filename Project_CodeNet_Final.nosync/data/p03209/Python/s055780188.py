# coding: utf-8
# Your code here!

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline

#n = int(input())
#n,a = [int(i) for i in readline().split()]
n,x = [int(i) for i in readline().split()]

sou = [1]*51
pat = [1]*51
for i in range(50):
    sou[i+1] = 2*sou[i]+3
    pat[i+1] = 2*pat[i]+1
#print(sou)
#print(pat)

# B L-1 P L-1 B
def solve(n,x):
    if x==0: return 0
    if n==0:
        if x == 0: return 0
        else: return 1

    if x <= sou[n-1]+1:
        return solve(n-1,x-1)
    elif x == sou[n-1]+2:
        return pat[n-1]+1
    elif x == sou[n]:
        return pat[n]
    else:
        return pat[n-1] + 1 + solve(n-1,x-sou[n-1]-2)
        
print(solve(n,x))        




