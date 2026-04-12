r,g,b = [int(i) for i in input().split()]

if (g*10+b)%4 == 0:
  print("YES")
else:
  print("NO")