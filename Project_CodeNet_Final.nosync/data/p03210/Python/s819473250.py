X = int(input())
xs = [3,7,5]
if any([X == x for x in xs]):
  print("YES")
else:
  print("NO")
