ri = lambda: map(int, input().split(' '))
L = [1]
C = [1]

def rec(n, x):
	if x == 0:
		return 0

	if n == 0:
		return 1

	if x == L[n]:
		return 2*C[n-1] + 1

	ans = 0
	if x >= L[n-1] + 2:
		ans += C[n-1] + 1
		ans += rec(n-1, x-L[n-1]-2)
	else:
		ans += rec(n-1, x-1)

	return ans

if __name__ == '__main__':
	N, X = ri()
	for i in range(1, N+1):
		L.append(2*L[i-1] + 3)
		C.append(2*C[i-1] + 1)
	ans = rec(N, X)
	print(ans)

