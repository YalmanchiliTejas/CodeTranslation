n = int(input())
a = list(map(int, input().split()))
m = 10 ** 9 + 7
s = sum(a) % m


sum = 0

for i in range(n):
  s -= a[i]
  if s < 0:
    s += m
  sum += a[i] * s
  sum %= m

print(sum)