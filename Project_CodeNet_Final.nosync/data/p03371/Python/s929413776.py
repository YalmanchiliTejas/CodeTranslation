a,b,c,x,y = map(int,input().split())
if a + b >= 2*c:
	if x >= y:
		ans = 2*y*c + (x-y)*min(a,2*c)
	else:
		ans = 2*x*c + (y-x)*min(b,2*c)
else:
	ans = (x*a + y*b)
print(ans)