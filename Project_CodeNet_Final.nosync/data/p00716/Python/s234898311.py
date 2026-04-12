# AOJ 1135: Ohgas' Fortune
# Python3 2018.7.14 bal4u

for cno in range(int(input())):
	a0, y, n = int(input()), int(input()), int(input())
	ans = 0
	for i in range(n):
		buf = list(input().split())
		k, r, f = int(buf[0]), float(buf[1]), int(buf[2])
		a = a0
		if k:
			for j in range(y):
				b = (int)(a*r)
				a += b-f
		else:
			c = 0
			for j in range(y):
				b = (int)(a*r)
				a -= f
				c += b
			a += c
		ans = max(ans, a)
	print(ans)

