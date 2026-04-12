n=int(input())
a=list(map(int,input().split()))
x=0
for i in range(n):
    x+=a[i]**2
y=sum(a)**2
print(((y-x)//2)%(10**9+7))