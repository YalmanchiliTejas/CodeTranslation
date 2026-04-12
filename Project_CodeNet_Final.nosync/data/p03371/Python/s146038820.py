#ABC095C
a,b,c,x,y=map(int,input().split())
ans=0
if a>2*c:
	ans+=2*c*x
	y=max(0,y-x)
	x=0
if b>2*c:
	ans+=2*c*y
	x=max(0,x-y)
	y=0
if a+b>2*c:
	p,q=max(x,y),min(x,y)
	ans+=2*c*q
	x-=q
	y-=q
if x>0:
	ans+=a*x
if y>0:
	ans+=b*y
print(ans)