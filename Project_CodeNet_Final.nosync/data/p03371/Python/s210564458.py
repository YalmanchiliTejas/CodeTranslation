a, b, c, x, y = [int(x) for x in input().split()]

ans1 = 2 * min(x, y) * c
if x >= y:
  ans1 += (x - y) * a
else:
  ans1 += (y - x) * b

ans2 = x * a + y * b

ans3 = 2 * max(x, y) * c

print(min(ans1, ans2, ans3))