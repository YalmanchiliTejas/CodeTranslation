import sys
input=sys.stdin.readline
from bisect import bisect_right
n=int(input())
A=[-int(input()) for _ in range(n)]
LIS=[]
for a in A:
    idx=bisect_right(LIS,a)
    if idx==len(LIS):
        LIS.append(a)
    else:
        LIS[idx]=a
print(len(LIS))