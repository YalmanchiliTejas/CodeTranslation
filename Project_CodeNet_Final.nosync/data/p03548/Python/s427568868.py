x,y,z=(int(i) for i in input().split())
#print(x,y,z)

ans=0
for i in range(100000):
  if z+i*y+i*z <= x:
    ans=i
    
print(ans)