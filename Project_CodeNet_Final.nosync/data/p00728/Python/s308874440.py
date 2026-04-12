# AOJ 1147: ICPC Score Totalizer Software
# Python3 2018.7.14 bal4u

while True:
	n = int(input())
	if n == 0: break
	s, vmin, vmax = 0, 1001, -1
	for i in range(n):
		a = int(input())
		vmin = min(vmin, a)
		vmax = max(vmax, a)
		s += a
	print((s-vmin-vmax)//(n-2))
