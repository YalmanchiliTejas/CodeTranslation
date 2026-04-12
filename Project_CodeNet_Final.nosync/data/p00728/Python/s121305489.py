while 1:
	n = input()
	if n == 0:
		break
	a = []
	for i in range(n):
		s = input()
		a.append(s)
	a = sorted(a)
	del a[n-1]
	del a[0]
	print sum(a)/(n-2)
