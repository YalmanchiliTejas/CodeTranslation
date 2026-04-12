# AOJ 2882: Generalized Leap Years
# Python3 2018.7.10 bal4u

while True:
	n, l, r = map(int, input().split())
	if n == 0: break
	A = [int(input()) for i in range(n)][::-1]
	y = [0]*(r+1)
	v = 2 - (n&1)	# v = 1 if n is odd
	for a in A:
		for i in range(a, r+1, a): y[i] = v
		v = 3-v
	ans = k = 0
	for i in range(l, r+1):
		if y[i] == 0: k += 1
		elif y[i] == 1: ans += 1
	if n & 1 == 0: ans += k
	print(ans)

