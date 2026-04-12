r, g, b = map(int, input().split())

aa = 10 * g + b
if aa % 4 == 0:
  print("YES")
else:
  print("NO")



