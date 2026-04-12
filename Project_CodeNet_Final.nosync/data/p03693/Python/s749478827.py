r,g,b = map(int,input().split())

if not((100*r+10*g+b)%4) :
  print("YES")
else:
  print("NO")

