from bisect import bisect_left
N=int(input())
A=[int(input()) for _ in range(N)]

L=[-1]*N
for i in A:
    n=bisect_left(L,i)
    L[n-1]=i

print(N-L.count(-1))