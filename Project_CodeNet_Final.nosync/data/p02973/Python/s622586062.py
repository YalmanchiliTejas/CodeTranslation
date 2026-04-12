import bisect
N=int(input())
A=[int(input()) for _ in range(N)]
color=[-1]*(N)
for a in A:
    i=bisect.bisect_left(color,a)
    color[i-1]=a
print(N-bisect.bisect_right(color,-1))