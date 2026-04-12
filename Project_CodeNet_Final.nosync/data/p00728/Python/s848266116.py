while 1:
	n = input()
	if n == 0: break
	print sum(sorted([int(raw_input()) for i in range(n)])[1:-1])/(n-2)