r,b,g = map(int,input().split())
n = 100*r + 10*b + g
if n % 4 == 0:
  print("YES")
else: print("NO")