a,b,c,x,y = map(int, input().split())

if a+b <= 2*c:
	print(a*x + b*y)
else:
	#買えるだけABピザを買う
	z = min(x,y)
	res = c * 2 * z
	#残り
	if x>=y:
		cand1 = (x-z)*a
	else:
		cand1 = (y-z)*b
	cand2 = (max(x,y)-z)*2*c
	print(min(cand1,cand2) + res)
