n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7
MOD2INV = 5 * 10 ** 8 + 4
total = 0
delta = 0

for i in range(n):
  total = (total + a[i]) % MOD
  delta = ((a[i]%MOD) * (a[i]%MOD) + delta)%MOD

result = ((((total * total) - delta + MOD) % MOD) * MOD2INV)%MOD
print(result)
