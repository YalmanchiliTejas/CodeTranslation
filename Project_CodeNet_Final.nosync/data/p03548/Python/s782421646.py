x,y,z=map(int,input().split())
n=1
while y*n+z*(n+1)<=x:
  n+=1
print(n-1)