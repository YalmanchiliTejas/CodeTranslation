H, W = map(int, raw_input().split())
board = []
for i in range(0, H):
	s = raw_input()
	lst = []
	for j in range(0, W):
		lst.append(s[j])
	board.append(lst)
down = []
for i in range(0, W):
	down.append(False)
for i in range(0, H):
	for j in range(0, W):
		if board[i][j] == '#': down[j] = True
for i in range(0, H):
	if '#' in board[i]:
		outs = ''
		for j in range(0, W):
			if down[j]: outs = outs + board[i][j]
		print outs