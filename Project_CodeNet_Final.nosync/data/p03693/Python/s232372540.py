r,g,b = map(int, input().split())
s = str(r) + str(g) + str(b)
if int(s) % 4 == 0:
  print("YES")
else:
  print("NO")