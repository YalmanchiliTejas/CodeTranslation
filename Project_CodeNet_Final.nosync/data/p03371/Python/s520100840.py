a,b,c,x,y=map(int,input().split())

mi=min([x,y])
ma=max([x,y])
g=ma-mi
ans,ab=0,0


if 2*c <= a+b:
  if x>=y:
    ans+=2*c*y + (x-y)*a
    ab=2*c*x
  else:
    ans+=2*c*x + (y-x)*b
    ab=2*c*y
else:
  ans+=a*x+b*y

if ab >= ans: 
  print(ans)
else:
  if ab!=0:
    print(ab)
  else:
    print(ans)
  