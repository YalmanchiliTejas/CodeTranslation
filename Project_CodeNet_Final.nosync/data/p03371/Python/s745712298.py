if __name__ == '__main__':
	a,b,c,x,y = map(int, input().split())

	if x==y:
		p = min(x*a+y*b, 2*x*c)
	elif x>y:
		p = min(x*a+y*b, 2*x*c, 2*y*c+(x-y)*a)
	else:
		p = min(x*a+y*b, 2*y*c, 2*x*c+(y-x)*b)

	print(p)