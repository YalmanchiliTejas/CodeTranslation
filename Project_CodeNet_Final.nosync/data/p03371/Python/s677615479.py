import sys

a,b,c,x,y=map(int,input().split())
ans=0
ans1=0

if a+b<=c*2:
  while x>0 and y>0:
    ans+=a+b
    x-=1
    y-=1

else:
  if (c*2>a and c*2>b) or (c>=a and x>=y) or (c>=b and y>x):
    while x>0 and y>0:
      ans+=c*2
      x-=1
      y-=1
  else:
    while x>0 or y>0:
      ans1+=c*2
      x-=1
      y-=1
    print(ans1)
    sys.exit()

if x==0:
  while y>0:
    ans+=b
    y-=1

else:
  while x>0:
    ans+=a
    x-=1

print(ans)