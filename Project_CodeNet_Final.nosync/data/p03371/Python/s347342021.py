a, b, c, x, y = map(int, input().split())
lis = []
for i in range(10**5+1):
  z = c * 2 * i + a * max(0, x-i) + b * max(0, y-i)
  lis.append(z)
print(min(lis))