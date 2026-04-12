a,b,c = map(int,input().split())

temp = b*10+c
if temp%4 == 0:
  print("YES")
else:
  print("NO")