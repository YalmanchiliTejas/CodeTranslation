r,g,b = map(int,input().split())
test = 100*r + 10*g + b
amari = test % 4
if amari == 0:
  print("YES")
else:
  print("NO")
