a, b, c, x, y = map(int, input().split())

count = a * x + b * y
for i in range(10 ** 6):
  num = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b
  if(count > num):
    count = num

print(count)
