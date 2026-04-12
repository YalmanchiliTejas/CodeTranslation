from bisect import bisect_right as br
import sys
input=sys.stdin.readline
#s=input()
#l=list(map(int,input().split()))
N=int(input())
A=[int(input()) for i in range(N)]
s=[A[-1]]
for i in range(N-2,-1,-1):
    k=br(s,A[i])
    if len(s)==k:
        s.append(A[i])
    else:
        s[k]=A[i]
print(len(s))
