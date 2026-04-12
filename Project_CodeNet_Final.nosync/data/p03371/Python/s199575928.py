a,b,c,x,y=map(int,input().split())
if x>y:
  a,b=b,a
  x,y=y,x
ans1=0
if a+b>2*c:
  ans1=2*x*c
else:
  ans1=x*a+x*b
y-=x
ans2=10**100
for i in range(y+1):
  tmp=b*i+c*2*(y-i)
  if tmp<ans2:
    ans2=tmp
print(ans1+ans2)