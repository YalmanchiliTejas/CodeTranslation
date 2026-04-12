x,y,z=map(int,input().split())
for i in range(1, x):
  if (y + z) * i + z > x:
    break
    
print(i -1)