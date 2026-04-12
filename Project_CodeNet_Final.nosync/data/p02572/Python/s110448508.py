m = int(input())
a = list(map(int, input().split()))

mod = 10**9 + 7
ans = 0

tmp_sum = sum(a[1:m]) % mod

for x in range(m-1):
  if a[x] % mod != 0:
    ans += (a[x] * tmp_sum) % mod
  
  tmp_sum -= a[x+1] % mod

print(ans%mod)