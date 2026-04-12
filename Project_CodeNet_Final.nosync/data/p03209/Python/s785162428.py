def ans(n, x):
	if n < 0:
		return 0
	if x < 1:
		return 0
	if x < 2 ** (n + 1) - 1:
		return ans(n - 1, x - 1)
	if x == 2 ** (n + 1) - 1:
		return 2 ** n
	return 2 ** n + ans(n - 1, x - 2 ** (n + 1) + 1)
N, X = map(int, input().split())
print(ans(N, X))