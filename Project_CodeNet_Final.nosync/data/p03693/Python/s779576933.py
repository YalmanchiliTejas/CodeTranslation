[r,g,b] = list(map(int, input().split()))
x = r*100 + g*10 + b
if x % 4 == 0:
  print("YES")
else:
  print("NO")
  