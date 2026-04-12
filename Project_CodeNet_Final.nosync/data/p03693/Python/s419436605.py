a, b, c = map(int, input().split())
t = int(str(a) + str(b) + str(c))
if t % 4 == 0:
  print("YES")
else:
  print("NO")