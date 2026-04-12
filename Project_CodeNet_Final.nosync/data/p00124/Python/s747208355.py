# AOJ 0124 League Match Score Sheet
# Python3 2018.6.21 bal4u

f = True
while True:
	n = int(input())
	if n == 0: break
	tbl = []
	for i in range(n):
		name, w, l, d = list(input().split())
		tbl.append([name, i, 3*int(w)+int(d)])
	if f: f = False
	else: print()
	for i in sorted(tbl, key=lambda x:(-x[2],x[1])): print(i[0], ',', i[2], sep='')

