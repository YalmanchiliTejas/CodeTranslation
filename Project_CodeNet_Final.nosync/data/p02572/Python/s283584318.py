n = int(input())
a = list(map(int,input().split()))
arr = [0]*(n+1)
ans = 0
mod = 10**9+7
for i in range(n):
  arr[i+1] += arr[i]+a[i]
  
for i in range(n):
  ans += (a[i]*(arr[n]-arr[i+1]))%mod
print(ans%mod)