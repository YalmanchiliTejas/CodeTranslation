A,B,C,X,Y = map(int,raw_input().split())
if C * 2 > A + B:
	print A * X + B * Y
else:
	x = C * 2 * min(X,Y)
	if X < Y:
		if C * 2 < B:
			print Y * 2 * C
		elif C * 2 < B:
			print A * X + B * Y
		else:
			y = (Y - X) * B
			print x+y
	else:
		if C * 2 < A:
			print X * 2 * C
		elif C * 2 < A:
			print A * X + B * Y
		else:
			y = (X - Y) * A
			print x+y