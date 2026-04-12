N = int(input())
b = list(map(int, input().split()))
MOD = 1000000007
sum_n = 0
a = []
for i in b:
  a.append(i%MOD)
sum_sum = sum(a[1:])
for i in range(N):

  sum_n = (sum_n + (a[i] * sum_sum) % MOD) % MOD
  if i+1 < N:
  	sum_sum = sum_sum - a[i+1]
print(sum_n % MOD)