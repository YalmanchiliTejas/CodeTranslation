r,g,b = input().split(" ")
r = int(r)
g = int(g)
b = int(b)
i = 100*r + 10*g + b
x = i % 4
if x==0:
  print("YES")
else:
  print("NO")