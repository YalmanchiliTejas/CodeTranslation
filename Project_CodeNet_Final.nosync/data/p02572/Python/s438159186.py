input()
v = list(map(int, input().split()))

MOD = int(1e9 + 7)
res = 0
sum = 0

for n in v:
  res = (res + (n % MOD * sum) % MOD) % MOD
  sum = (sum + n) % MOD

print(res)
