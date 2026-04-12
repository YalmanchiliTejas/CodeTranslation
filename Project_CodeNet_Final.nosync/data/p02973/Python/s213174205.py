import sys
input=sys.stdin.readline
from bisect import bisect_right
n=int(input())
A=[-int(input())-1 for _ in range(n)]
M=[0]*n
for a in A:
    idx=bisect_right(M,a)
    M[idx]=a
print(sum(m!=0 for m in M))