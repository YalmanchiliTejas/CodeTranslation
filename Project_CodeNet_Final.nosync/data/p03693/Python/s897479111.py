rgb = list(input().split())
if int(''.join(rgb[1:3])) % 4 == 0:
  print("YES")
else:
  print("NO")


