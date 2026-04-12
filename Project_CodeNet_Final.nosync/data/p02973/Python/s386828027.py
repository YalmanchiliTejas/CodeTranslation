from bisect import bisect_right,bisect_left
n=int(input())
a=[int(input()) for _ in range(n)]
INF=float('INF')
l=[INF]*n
for i in a[::-1]:
    l[bisect_right(l,i)]=i
print(bisect_left(l,INF))