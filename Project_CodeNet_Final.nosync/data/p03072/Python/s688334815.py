N = int(input())
H = list(map(int, input().split()))
if N == 1:
	print(1)
else:
	ans = 1
	x = H[0]
	for i in range(1, N):
		if H[i] >= x:
			ans += 1
			x = H[i]
	print(ans)