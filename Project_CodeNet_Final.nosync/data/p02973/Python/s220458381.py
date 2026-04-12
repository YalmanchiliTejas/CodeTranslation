from bisect import bisect_left
n=int(input())
x=[-1]*n
for _ in range(n):
    a=int(input())
    i=bisect_left(x,a)-1
    x[i]=a
print(n-x.count(-1))
