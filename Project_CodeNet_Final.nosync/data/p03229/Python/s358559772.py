N = int(input())
A = [0] * N

for i in range(N):
	A[i] = int(input())

A.sort()

ans = 0

for t in range(2):
	coef = [0] * N
	for i in range(N):
		k = 0
		if i == 0 or i == N-1:
			k = 1 
		else:
			k = 2
		if (t + i) % 2 == 1:
			k = -k
		coef[i] = k
	coef.sort()

	val = 0
	for i in range(N):
		val += coef[i] * A[i]

	ans = max(ans, val)

print(ans)