while 1:
	n,a,b,c,x=map(int,raw_input().split())
	if n==0:break
	reel=map(int,raw_input().split())
	roop,i=-1,0
	while i<n:
		roop+=1
		if roop>10000:
			roop=-1
			break
		if x==reel[i]:
			i+=1
		x=(a*x+b)%c
	print roop