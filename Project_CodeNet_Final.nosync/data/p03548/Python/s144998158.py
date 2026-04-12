x, y, z = map(int,input().split())
i = 1
while (y*i+z*(i+1)) <= x:
  i += 1 
print(i-1)