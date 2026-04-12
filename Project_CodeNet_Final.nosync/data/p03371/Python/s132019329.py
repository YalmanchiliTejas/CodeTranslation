a,b,c,x,y=list(map(int,input().split()))
mxy=min([x,y])
Mxy=max([x,y])
mab=min([a,b])
ans=0
if 2*c<a+b:
	ans+=2*c*mxy
	if x<y:
		ans+=b*(y-mxy)
	else:
		ans+=a*(x-mxy)
else:
	ans=a*x+b*y

if ans>2*c*Mxy:
	ans=2*c*Mxy

print(ans)