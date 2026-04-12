a,b,c,x,y=map(int,input().split())
if x<y:
  min,max=x,y
  a2,b2=a,b
else:
  min,max=y,x
  a2,b2=b,a

if c*2<=a2+b2:
  res=2*min*c
  tmp1=(max-min)*b2
  tmp2=2*(max-min)*c
  if tmp1<tmp2:
    print(res+tmp1)
  else:
    print(res+tmp2)
else:
  if a2>b2:
    a2,b2=b2,a2
    min,max=max,min
  tmp1=a2*min+b2*max
  tmp2=2*max*c
  if min>max:
    tmp2+=(min-max)*a2
  if tmp1<tmp2:
    print(tmp1)
  else:
    print(tmp2)