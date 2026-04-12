n,*a=map(int,open(0).read().split())
p=0
c=0
for i in range(n):
    if p<=a[i]:
        c+=1
        p=a[i]
print(c)