x, y, z = map(int, input().split())
x = x-z
c = y+z
n = 0
while 0 < x:
  if c <= x:
    n = n+1
    x = x-c
  else:
    break
print(n)