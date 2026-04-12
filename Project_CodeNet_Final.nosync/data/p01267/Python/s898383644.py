while True:
	N, A, B, C, X = (int(x) for x in raw_input().split())
	if N == 0: break
	Y = [int(x) for x in raw_input().split()]
	for frame in xrange(10001):
		if X == Y[0]:
			Y.pop(0)
			if not Y:
				print frame
				break
		X = (A * X + B) % C
	else:
		print -1