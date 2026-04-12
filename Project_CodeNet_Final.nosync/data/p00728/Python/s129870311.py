while True:
	n = int(input())
	if n == 0:
	   break
	s, vn, vx = 0, 1001, -1
	for i in range(n):
		a = int(input())
		vn = min(vn, a)
		vx = max(vx, a)
		s += a
	print((s-vn-vx)//(n-2))
