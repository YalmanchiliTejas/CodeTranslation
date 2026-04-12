r, g, b = list(input().split())
x = int(r+g+b)
 
if x % 4 == 0:
  print("YES")
else:
  print("NO")