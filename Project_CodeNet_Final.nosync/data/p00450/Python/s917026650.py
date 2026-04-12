# AOJ 0527: Setting Go Stones
# Python3 2018.7.1 bal4u

while True:
	n = int(input())
	if n == 0: break
	a, c = [0]*100005, [0]*100005
	sz, a[0], c[0] = 0, 1, int(input())
	for i in range(n-1):
		color = int(input())
		if c[sz] == color: a[sz] += 1
		elif i & 1:
			sz += 1
			a[sz] = 1
		else:
			if sz == 0: a[sz] += 1
			else:
				a[sz-1] += a[sz]+1
				sz -= 1
		c[sz] = color;
	ans = 0
	for i in range(sz+1):
		if c[i] == 0: ans += a[i]
	print(ans)
