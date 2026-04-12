while 1:
	n = input()
	if n == 0:break
	D = range(1,7)
	ans = 1
	for i in range(n):
		c = raw_input()[0]
		if c == "N":
			D = [D[1],D[5],D[2],D[3],D[0],D[4]]
		elif c == "S":
			D = [D[4],D[0],D[2],D[3],D[5],D[1]]
		elif c == "E":
			D = [D[3],D[1],D[0],D[5],D[4],D[2]]
		elif c == "W":
			D = [D[2],D[1],D[5],D[0],D[4],D[3]]
		elif c == "R":
			D = [D[0],D[2],D[4],D[1],D[3],D[5]]
		elif c == "L":
			D = [D[0],D[3],D[1],D[4],D[2],D[5]]
		ans += D[0]
	print ans