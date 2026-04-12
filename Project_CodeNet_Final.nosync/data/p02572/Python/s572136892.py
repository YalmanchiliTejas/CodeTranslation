n=int(input())
a=list(map(int,input().split()))
x=0
for i in range(n):
  x+=a[i]
x=x**2
y=0
for j in range(n):
  y+=a[j]**2
z=(x-y)//2
print(z%(10**9+7))