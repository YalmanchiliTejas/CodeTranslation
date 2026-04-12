a , b , c , x , y = map(int , input().split())
if a / 2 + b / 2 >= c:
  ans = min(x , y) * 2 * c 
  if x > y:
    ans += (x - y) * a
  elif x < y:
    ans += (y - x) * b
else:
  ans = a * x + b * y
print(ans if c * max(x , y) * 2 > ans else  c * max(x , y) * 2)