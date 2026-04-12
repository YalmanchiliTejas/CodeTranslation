a,b,c,x,y=map(int,input().split())
sum=0
tmp=min(x,y)
if a+b>=2*c:
  sum+=2*c*tmp
  x-=tmp
  y-=tmp
  if x==0:
    if b>=2*c:
      sum+=2*c*y
    else:
      sum+=b*y
  elif y==0:
    if a>=2*c:
      sum+=2*c*x
    else:
      sum+=a*x
else:
  sum+=a*x+b*y
print(sum)