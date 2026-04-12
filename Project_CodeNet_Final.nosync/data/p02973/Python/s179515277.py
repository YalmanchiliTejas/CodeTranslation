import bisect
n=int(input())
a=[int(input()) for i in range(n)]
l=[-1]*n
ans=0
for i in range(n):
  l[bisect.bisect_left(l,a[i])-1]=a[i]
print(n-l.count(-1))