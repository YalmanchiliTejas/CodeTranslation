#--RGB Cards
a, b, c = map(int, input().split())

rgb = 100*a + 10*b + c

if (rgb % 4 == 0):
  print("YES")
else:
  print("NO")
  