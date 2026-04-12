a,b,c,x,y=[int(x) for x in input().split()]
p=0
if a>=c and b>=c:
  p_1=c*min(x,y)*2
  if x>y:
    p_1+=a*(x-y)
  elif y>x:
    p_1+=b*(y-x)
  p_2=c*max(x,y)*2
  p=min(p_1,p_2)
elif a<=c and b<=c:
  p=a*x+b*y
elif a<=c and c<=b:
  p_1=a*x+b*y
  p_2=c*min(x,y)*2
  if x>y:
    p_2+=a*(x-y)
  elif y>x:
    p_2+=b*(y-x)
  p_3=c*max(x,y)*2
  p=min(p_1,p_2,p_3)
elif b<=c and c<=a:
  p_1=a*x+b*y
  p_2=c*min(x,y)*2
  if x>y:
    p_2+=a*(x-y)
  elif y>x:
    p_2+=b*(y-x)
  p_3=c*max(x,y)*2
  p=min(p_1,p_2,p_3)
print(p)