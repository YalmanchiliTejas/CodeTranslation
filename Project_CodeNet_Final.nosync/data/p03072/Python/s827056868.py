n=int(input())
a=[int(i) for i in input().split()]
c=1
m=a[0]
for i in range(1,n):
    if a[i]>=m:
        c+=1
    if a[i]>m:
        m=a[i]
print(c)