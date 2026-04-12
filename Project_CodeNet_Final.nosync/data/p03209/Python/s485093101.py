n,x=map(int,input().split())

d=[1 for i in range(n+1)]
p=[1 for i in range(n+1)]

for i in range(1,n+1):
  d[i]=2*d[i-1]+3
  p[i]=2*p[i-1]+1

def bp(n,x):
  if x==d[n]:
    return p[n]
  if x==1:
    return 0
  if x==2+d[n-1]:
    return 1+p[n-1]
  if x<2+d[n-1]:
    return bp(n-1,x-1)
  if x<d[n]:
    return 1+p[n-1]+bp(n-1,x-d[n-1]-2)

print(bp(n,x))
