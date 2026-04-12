r,g,b = map(int,input().split())
s = str(r)+str(g)+str(b)
s = int(s)
if s%4 == 0:
  print("YES")
else:
  print("NO")