x,y,z = map(int, input().split())

n = 1
while x >= (n+1)*z + n*y:
  n += 1
print(n-1)