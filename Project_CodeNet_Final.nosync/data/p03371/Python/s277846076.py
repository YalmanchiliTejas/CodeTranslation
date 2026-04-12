a, b, c, x, y = map(int, input().split())
ans = 10 ** 15
for i in range(max(x, y) * 2 + 1):
  if x - i//2 < 0 and y - i//2 < 0:
    n = c * i 
  elif x - i//2 < 0:
    n = c * i + (y - i//2) * b
  elif y - i//2 < 0:
    n = c * i + (x - i//2) * a
  else:
    n = c * i + (x - i//2) * a + (y - i//2) * b
  ans = min(ans, n)
print(ans)  
