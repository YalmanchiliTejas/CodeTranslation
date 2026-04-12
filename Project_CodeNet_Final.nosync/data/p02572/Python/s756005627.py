n = int(input())
a = list(map(int,input().split()))
MOD = 10**9+7

array_sum = 0
for i in range(n):
  array_sum += a[i]
  array_sum %= MOD

ans = 0
for i in range(n):
  array_sum -= a[i]
  ans += array_sum * a[i]
  ans %= MOD
  
print(ans)