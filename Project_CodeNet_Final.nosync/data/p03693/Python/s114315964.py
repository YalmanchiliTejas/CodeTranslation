r,g,b = map(str,input().split())
GB = int(g + b)

if GB%4 == 0:
  print("YES")
else:
  print("NO")