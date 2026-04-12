a, b, c = map(int, input().split())

d = b * 10 + c

if d % 4 == 0:
  print("YES")
else:
  print("NO")