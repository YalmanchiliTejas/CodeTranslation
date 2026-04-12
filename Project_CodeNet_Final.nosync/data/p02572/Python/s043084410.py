n = int(input())
a = list(map(int,input().split()))

mod= 10**9+7

A = sum(a)

ans=0

for i in a:
  A -= i
  A%=mod
  ans += A*i
  ans%=mod
print(ans)
  
