N = int(input())
A = list(map(int, input().split()))

s = sum(A)
sumpro = 0

for a in A[:-1]:
	s -= a
	sumpro += a * s

print(sumpro % (10 ** 9 + 7))
