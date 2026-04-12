a,b,c,x,y=map(int,input().split())
yasui=False
yasuia=False
yasuib=False
ans=0
sa=max([x,y])-abs(x-y)
if a+b>2*c:
  yasui=True
if a>2*c:
  yasuia=True
if b>2*c:
  yasuib=True
if yasui:
  ans+=sa*2*c
else:
  ans+=sa*(a+b)
x-=sa
y-=sa

if x>0:
  if yasuia:
    ans+=2*c*x
  else:
    ans+=a*x
if y>0:
  if yasuib:
    ans+=2*c*y
  else:
    ans+=b*y
print(ans)