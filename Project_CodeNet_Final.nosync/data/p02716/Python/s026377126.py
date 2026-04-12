n=int(input())
a=[int(j) for j in input().split()]
p=[0]*n
d=[0]*n
for i in range(n):
    p[i]=a[i]+p[i-2]
    if (i&1):
        d[i]=max(p[i-1],a[i]+d[i-2])
    else:
        d[i]=max(d[i-1],a[i]+d[i-2])
print(d[-1])