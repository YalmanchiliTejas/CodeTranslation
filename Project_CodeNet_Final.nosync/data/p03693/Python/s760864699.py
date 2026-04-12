def is_multiple_of_four(r, g, b):
  l2d = int(g)*10+int(b) # last 2 digits
  print("YES") if l2d%4 == 0 else print("NO")

r, g, b = input().split(" ")
is_multiple_of_four(r, g, b)

