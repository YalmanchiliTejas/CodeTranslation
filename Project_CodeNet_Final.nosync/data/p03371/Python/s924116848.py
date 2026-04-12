a, b, c, x, y = map(int, input().split())

ans = 0
if a + b >= 2 * c:
  ans += 2 * c * min(x, y)
  
  if x > y:
    
    if a >= 2 * c:
      ans += (x - y) * 2 * c
    else:
      ans += (x - y) * a
      
  elif x < y:
    
    if b >= 2 * c:
      ans += (y - x) * 2 * c
    else:
      ans += (y - x) * b
      
else:
  ans += a * x + b * y
  
print(ans)