a, b, c, x, y = [int(elem) for elem in input().split()]

res = -1
for i in range(0, 10 ** 5 + 1):
  cand = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b
  if res == -1:
    res = cand
  else:
    if res > cand:
      res = cand
print(res)