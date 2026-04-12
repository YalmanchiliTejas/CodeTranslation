mod = 10 ** 9 + 7
n = int(input())

a_sum = 0
sq_sum = 0
for a in map(int, input().split()):
  a_sum = (a_sum + a) % mod
  sq_sum = (sq_sum + a * a) % mod
res = (a_sum * a_sum - sq_sum) % mod
print(-(mod // 2) % mod * res % mod)