n = int(input())
a_list = list(map(int, input().split(' ')))
mod = 10**9 + 7

sum_ = sum(a_list)
result = 0
for a in a_list:
  sum_ -= a
  result += ((sum_ % mod) * a) % mod
  result = result % mod

print(result)