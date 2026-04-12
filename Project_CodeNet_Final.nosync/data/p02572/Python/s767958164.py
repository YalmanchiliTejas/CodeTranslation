n = int(input())
a = list(map(int, input().split()))
s = sum(a)

all_sum = 0
count = 1

for i in range(n - 1):
  s -= a[i]
  all_sum += a[i] * s

print(all_sum % (10 ** 9 + 7))