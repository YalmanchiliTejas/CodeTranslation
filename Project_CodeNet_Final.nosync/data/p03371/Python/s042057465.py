a,b,c,x,y=map(int,input().split())
m=10**10
for i in range(2*(x+y)+1):
  m=min(m,max(0,x-i//2)*a+max(0,y-i//2)*b+i*c)
print(m)
  