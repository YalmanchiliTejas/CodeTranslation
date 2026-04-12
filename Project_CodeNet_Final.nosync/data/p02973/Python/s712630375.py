import sys
import bisect
input=sys.stdin.readline

N=int(input())
A=[-int(input()) for _ in range(N)]
l=[A[0]]
for x in A[1::]:
    tmp=bisect.bisect(l,x)
    if tmp==len(l):l.append(x)
    else: l[tmp]=x
print(len(l))