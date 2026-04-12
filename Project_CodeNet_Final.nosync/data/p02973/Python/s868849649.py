from bisect import bisect as br
n=int(input())
x=[-1]*n
for _ in range(n):
    a=int(input())
    i=br(x,a-1)-1
    x[i]=a
print(n-x.count(-1))
