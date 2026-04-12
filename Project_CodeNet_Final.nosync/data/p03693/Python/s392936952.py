r, g, b = map(int, input().split())

Number = r * 100 + g *10 + b

if (Number % 4) == 0:
  print("YES")
else:
  print("NO")