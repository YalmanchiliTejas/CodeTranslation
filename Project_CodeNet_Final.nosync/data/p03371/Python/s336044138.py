a, b, c, x, y = [int(i) for i in input().split()]
#print(a, b, c, x, y)

z=max(x,y)

ans=1000000000000
for k in range(0,z+1):
  i=x-k
  if i<0:
    i=0
  j=y-k
  if j<0:
    j=0
  price=a*i+b*j+2*c*k
  if price < ans:
    ans = price
    
print(ans)