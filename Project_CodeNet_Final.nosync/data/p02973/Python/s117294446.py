from bisect import bisect_right
import sys
input=sys.stdin.readline
n=int(input())
A=[-int(input())-1 for _ in range(n)]
M=[0]*n
for a in A:
    idx=bisect_right(M,a)
    M[idx]=a
ans=0
for m in M:
    if m:
        ans+=1
print(ans)