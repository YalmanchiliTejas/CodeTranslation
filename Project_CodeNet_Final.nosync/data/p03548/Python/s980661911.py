x,y,z=map(int,input().split())
temp=z
result=0
while temp<=x-y-z:
  temp=temp+y+z
  result=result+1
print(result)