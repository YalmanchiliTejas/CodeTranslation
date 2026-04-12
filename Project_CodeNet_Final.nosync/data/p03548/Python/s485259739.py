x, y, z = map(int, input().split() )

cnt = 0
x = x - z

while( x >= y+z ):
  cnt += 1
  x = x - y -z
  
print(cnt)