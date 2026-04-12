# AOJ 0195 What is the Most Popular Shop in Tokaich
# Python3 2018.6.20 bal4u

import sys
while True:
	tbl = {}
	for i in range(5):
		s = sum(list(map(int, input().split())))
		if i == 0 and s == 0: sys.exit()
		tbl[chr(ord('A')+i)] = s
	ans = sorted(tbl.items(), key=lambda x: x[1], reverse = True)
	print(*ans[0])

