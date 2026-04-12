n=int(input())
a=list(map(int,input().split()))

ans=0
x=0
for i in range(n):
  ans += a[i] * x
  x +=a[i]
print(ans%(10**9+7))
