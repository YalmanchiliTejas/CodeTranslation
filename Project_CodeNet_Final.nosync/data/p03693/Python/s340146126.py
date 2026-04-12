r,g,b = [int(i) for i in input().split()]
if (10*g+b)%4 == 0:
  print("YES")
else:
  print("NO")