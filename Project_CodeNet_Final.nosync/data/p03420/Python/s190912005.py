n, k = map(int, input().split())
ans = 0

if k == 0:
	print(n ** 2)
else:
	for i in range(k + 1, n + 1):
		div = n // i
		ans += (i - k) * div
		if n % i != 0:
			ans += max(n + 1 - ((n // i) * i + k), 0)

	print(ans)