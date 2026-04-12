(a, b, c, wanted_a, wanted_b) = (int(tok) for tok in input().split())

res = wanted_a * a + wanted_b * b
for both in range(max(wanted_a, wanted_b) * 2 + 1):
  left_a = wanted_a - both // 2
  left_b = wanted_b - both // 2
  cost = both * c + max(0, left_a) * a + max(0, left_b) * b
  res = min(res, cost)

print(res)
