x,y,z = map(int, input().split())

X = x - 2*z
n = X//(y+z)

if X - (y+z)*n >= y:
  print(n+1)
else:
  print(n)
