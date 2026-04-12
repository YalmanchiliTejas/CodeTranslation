# AOJ 0078 Magic Square
# Python3 2018.6.17 bal4u

MAX = 15

tbl = [0]*MAX
while True:
	n = int(input())
	if n == 0: break
	tbl = [[0 for r in range(n)] for c in range(n)]
	r, c = n//2+1, n//2
	tbl[r][c] = i = 1
	while i < n*n:
		r += 1
		c += 1
		while True:
			if c >= n: c = 0;
			elif c < 0: c = n - 1;
			if r >= n: r = 0;
			if tbl[r][c] == 0:
				i += 1
				tbl[r][c] = i
				break
			r += 1
			c -= 1

	for r in range(n):
		for c in range(n):
			print(format(tbl[r][c], '4d'), end='')
		print()
