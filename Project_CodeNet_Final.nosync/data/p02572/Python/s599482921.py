n=int(input())
a=list(map(int,input().split()))
b=[0]*n
b[0]=a[0]
for i in range(1,n):
  b[i]=b[i-1]+a[i]
x=0
for i in range(1,n)[::-1]:
  x+=(b[i-1]*a[i])
  x=x%(10**9+7)
print(x)