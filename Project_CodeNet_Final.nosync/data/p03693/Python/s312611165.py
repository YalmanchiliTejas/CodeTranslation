r,g,b = map(int,input().split())
K = 100*r + 10*g + b
if K%4 ==0:
  print("YES")
else:
  print("NO")