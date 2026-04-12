n=int(input())
a=list(map(int,input().split()))
x=sum(a)**2
total=0
for i in range(n):
    total+=a[i]**2
y=int((x-total)//2)
print(y%(10**9+7))