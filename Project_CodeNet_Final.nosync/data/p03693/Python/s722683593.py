a, b, c = map(int, input().split())

e = a*100+b*10+c
if e%4 == 0:
  print("YES")
else:
  print("NO")