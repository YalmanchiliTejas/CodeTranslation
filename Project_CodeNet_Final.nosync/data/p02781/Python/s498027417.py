from itertools import combinations, product
from math import factorial

def nCr(n, r):
  return int(factorial(n) / factorial(n - r) / factorial(r))

n = int(input())
k = int(input())
size = len(str(n))
count = 0 if k > size - 1 else nCr(size - 1, k) * (9 ** k)
if k == 1:
  count += sum(i * (10 ** (size - 1)) <= n for i in range(1, 10))
else:
  first = int(str(n)[0])
  count += 0 if k > size else (first - 1) * nCr(size - 1, k - 1) * (9 ** (k - 1))
  for digits in combinations(range(size - 1), k - 1):
    count += sum(
      sum(num * (10 ** digit) for num, digit in zip(nums, digits)) <= n % (10 ** (size - 1))
      for nums in product(range(1, 10), repeat = k - 1)
    )
print(count)
