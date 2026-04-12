X = input()

try:
  X = int(X)
except:
  X = -1
  
if X in (3, 5, 7):
  print("YES")
else:
  print("NO")