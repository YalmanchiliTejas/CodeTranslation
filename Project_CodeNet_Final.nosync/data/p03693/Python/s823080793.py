R, G, B = (int(i) for i in input().split())
ans = 100 * R + 10 * G + B

if ans%4 == 0:
  print("YES")
else:
  print("NO")
