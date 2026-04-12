r,g,b = map(str,input().split())

S = r + g + b

if int(S) % 4 == 0:
  print("YES")
else:
  print("NO")