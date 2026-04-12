from itertools import accumulate

n = int(input())
a = [int(x) for x in input().split()]
p = list(accumulate(a))
m = 10 ** 9 + 7

result = 0
for i, x in enumerate(a):
  result += x * (p[-1] - p[i])
  result %= m

print(result)