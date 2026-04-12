a,b,c,x,y=map(int,input().split())
ans=0
if a>c*2 and b>c*2:
  ans+=max(x,y)*2*c
elif a>c*2:
  if x>y:
    ans+=2*c*x
  else:
    ans+=2*c*x+(y-x)*b
elif b>c*2:
  if x>y:
    ans+=2*c*y+(x-y)*a
  else:
    ans+=2*c*y
elif a+b>c*2:
  if x>y:
    ans+=2*c*y+(x-y)*a
  else:
    ans+=2*c*x+(y-x)*b
else:
  ans+=a*x+b*y
print(ans)