s1 = list(map(int,input().split()))
rgb = s1[0] * 100 + s1[1] * 10 + s1[2]
if int(rgb) % 4 == 0:
  print("YES")
else:
  print("NO")
