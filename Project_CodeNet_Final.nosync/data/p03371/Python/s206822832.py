a,b,c,x,y = map(int, input().split())
mina = min(a, 2*c)
minb = min(b, 2*c)
minab = min(a+b,2*c)

if x >= y:
	answer = (minab * y) + (mina * (x-y))
else:
	answer = (minab * x) + (minb * (y-x))
	
print(answer)
