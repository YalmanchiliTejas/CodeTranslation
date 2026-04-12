a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
m = max(x, y)
for i in range(1, m+1):
  x -= 1
  y -= 1
  if x < 0:
    x = 0
  if y < 0:
    y = 0
  temp = c*(i*2) + x*a + y*b
  if temp < ans:
    ans = temp

print(ans)
