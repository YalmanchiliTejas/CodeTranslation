r,g,b = map(int, input().split())
total = r*100 + g*10 + b
mod = total % 4
if (mod == 0):
  print("YES")
else:
  print("NO")