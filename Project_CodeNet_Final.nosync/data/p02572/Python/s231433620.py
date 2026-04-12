n = int(input())
a = list(map(int, input().split(' ')))

s = [0 for i in range(n-1)]
s[0] = sum(a) - a[0]
for i in range(1, n-1):
  s[i] = s[i-1] - a[i]

ans = 0
mod = 10 ** 9 + 7

for i in range(n - 1):
  k = a[i] * s[i] % mod
  ans += k
  ans %= mod
    
print(ans)