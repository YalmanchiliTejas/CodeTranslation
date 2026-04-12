a, b, c, x, y = list(map(int, input().split()))

total1 = min(a+b, 2*c) * min(x, y)

if x > y:
  total1 += (x-y) * a
elif y > x:
  total1 += (y-x) * b

total2 = max(x, y) * 2*c

print(min(total1, total2))