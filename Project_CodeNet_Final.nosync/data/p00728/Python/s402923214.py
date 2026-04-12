while True:
	n = int(input())
	if n == 0:
		break
	s = [int(input()) for _ in range(n)]
	s.sort()
	print(sum(s[1:n-1])//(n-2))
