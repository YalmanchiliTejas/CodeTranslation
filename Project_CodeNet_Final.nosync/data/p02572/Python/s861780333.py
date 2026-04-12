n = int(input())
lst = [int(i) for i in input().split()]
mod = pow(10, 9) + 7
ans = 0
summ = 0
for i in range(1, n):
  summ += lst[i]
  summ %= mod
for i in range(n - 1):
  ans += lst[i] * summ
  ans %= mod
  summ -= lst[i + 1]
  summ %= mod
print(ans)