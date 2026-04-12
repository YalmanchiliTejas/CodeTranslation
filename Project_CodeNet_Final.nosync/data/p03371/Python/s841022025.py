a,b,c,x,y = map(int,input().split())
total = 0
if (a//2-c//2)+(b//2-c//2) >= 0:
	if x<=y:
		total += x*c*2
		if (y-x)*c*2 <= (y-x)*b:
			total += (y-x)*c*2
		else:
			total += (y-x)*b
	else:
		total += y*c*2
		if (x-y)*c*2 <= (x-y)*a:
			total += (x-y)*c*2
		else:
			total += (x-y)*a
else:
	total += (x*a+y*b)
print(total)