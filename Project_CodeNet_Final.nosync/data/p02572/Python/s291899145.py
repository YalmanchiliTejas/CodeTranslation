n = int(input())
A = list(map(int,input().split()))
a = [0]
for i in range(n):
  a.append(a[i]+A[i])
ans = 0
mod = 10**9+7
for i in range(1,n):
  ans += a[i]*A[i]%mod
print(ans%mod)