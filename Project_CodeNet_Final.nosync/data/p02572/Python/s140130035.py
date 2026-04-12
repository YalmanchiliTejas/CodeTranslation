PRIME = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))

b = [0 for i in range(n - 1)]
b[0] = a[0]

for i in range(1, n - 1):
  b[i] = (b[i - 1] + a[i]) % PRIME

ans = 0
for i in range(n - 1):
  ans += (b[i] * a[i + 1]) % PRIME
  ans %= PRIME

print(ans)