while True:
	n = input()
	if n == 0: break
	board = [[0] * n for i in range(n)]
	xp = n / 2
	yp = n / 2 + 1
	for i in range(n ** 2):
		if board[yp][xp] == 0:
			board[yp][xp] = i + 1
		else:
			xp -= 1
			yp += 1
			if xp == -1: xp = n - 1
			if yp == n : yp = 0
			board[yp][xp] = i + 1
		yp += 1
		xp += 1
		if xp == n: xp = 0
		if yp == n: yp = 0
	for b in board:
		print "".join(map(lambda x:str("% 4d" % x), b))