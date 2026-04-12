a, b, c = map(int, list(input().split(" ")) )
s = 100*a + 10*b + c
if s % 4 == 0:
  print("YES")
else:
  print("NO")