n=int(input())
a=list(map(int,input().split()))
x=(sum(a))**2
y=0
p=10**9+7
for i in range(n):
    y+=a[i]**2
print((x-y)//2%p)