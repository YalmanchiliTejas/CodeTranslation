while 1:
	n,a,b,c,x = map(int, raw_input().split(" "))
	if (n,a,b,c,x) == (0,0,0,0,0):
		break
	y = [0]
	y[1:] = map(int, raw_input().split(" "))
	frame = -1
	for i in range(1,n+1):
		frame += 1
		while frame <= 10000 :
			tmpx = x
			x = (a * x + b) % c
			if tmpx == y[i]:
				break
			frame += 1
		else :
			frame = - 1
			break
	print frame