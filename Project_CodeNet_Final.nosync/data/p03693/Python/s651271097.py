r,g,b = map(int, input().split())
A = g * 10 + b
if A % 4 == 0:
  print("YES")
else:
  print("NO")