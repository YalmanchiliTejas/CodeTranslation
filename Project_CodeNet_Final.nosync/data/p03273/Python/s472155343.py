H, W = map(int, input().split())
hmax = H
board = []
for _ in range(H):
	line = list(input().rstrip())
	if '#' in line:
		board.append(line)
	else: hmax -= 1

cnt = [0] * W
for line in board:
	for w, px in enumerate(line):
		if px == '.': cnt[w] += 1

for line in board:
	for w, px in enumerate(line):
		if cnt[w] == hmax: continue
		else: print(px, end='')
	print()