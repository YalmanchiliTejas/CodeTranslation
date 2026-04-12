r,g,b = map(str, input().split())
judge = int(r+g+b)
if judge%4 ==0:
  print("YES")
else:
  print("NO")