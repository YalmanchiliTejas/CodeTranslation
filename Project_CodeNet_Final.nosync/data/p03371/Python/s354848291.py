a,b,c,x,y = map(int,input().split())
ans = 0
if a+b > 2*c:
	ans = c*2*min(x,y)
	if x<y:
		if b > 2 * c:
			ans += 2*c*(y-x)
		else:
			ans += b*(y-x)
	else:
		if a > 2 * c:
			ans += 2*c*(x-y)
		else:
			ans += a*(x-y)
else:
	ans = a*x+b*y	
print(ans)
