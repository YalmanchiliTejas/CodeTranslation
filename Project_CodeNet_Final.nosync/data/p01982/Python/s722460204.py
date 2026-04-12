
while True:
	n,l,r = map(int,input().split())
	if n == 0:
		break
	a = []
	for _ in range(n):
		a.append(int(input()))
	a.append(1)
	ans = 0
	for i in range(l,r+1):
		for j,aa in enumerate(a):
			if i % aa == 0:
				if j % 2 == 0:
					ans += 1
				break
	print(ans)
