r,g,b = map(str,input().split())
s = int(r+g+b)
if s%4 == 0:
  print("YES")
else:
  print("NO")