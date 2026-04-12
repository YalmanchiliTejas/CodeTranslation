a,b,c,x,y=map(int,input().split())
r=float('inf')
for i in range((10**5)+1):
  r=min(r,i*2*c+max(0,x-i)*a+max(0,y-i)*b)
print(r)