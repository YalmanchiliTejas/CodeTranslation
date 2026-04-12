a,b,c,x,y=list(map(int, input().split()))
ans=0

if (a+b)>=c*2:
	if x>y:
		ans=ans+(y*2*c)
		x=x-y
		y=0
	else:
		ans=ans+(x*2*c)
		y=y-x
		x=0

if a>c*2:
	if x>0:
		ans=ans+(x*2*c)
		x=0
elif x>0:
	ans=ans+(x*a)
	x=0

if b>c*2:
	if y>0:
		ans=ans+(y*2*c)
		y=0
elif y>0:
	ans=ans+(y*b)
	y=0

print(ans)