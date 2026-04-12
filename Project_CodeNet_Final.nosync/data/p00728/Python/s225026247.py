while True:
	n = int(input())
	if n == 0:
		break
	s = []
	for i in range(n):
		s.append(int(input()))
	s.sort()
	del s[0]
	del s[-1]
	print(sum(s)//len(s))
