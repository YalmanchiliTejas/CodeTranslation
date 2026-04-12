r,g,b = map(int,input().split())

x = str(r) + str(g) + str(b)

num = int(x)

if num % 4 ==0:
  print("YES")
else:
  print("NO")