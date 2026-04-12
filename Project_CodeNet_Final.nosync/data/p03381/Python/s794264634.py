N = int(input())
X = list(map(int, input().split()))
Y = sorted(X)

a = Y[int(N / 2 - 1)]
b = Y[int(N / 2)]
for i in range(N):
	if X[i] <= a:
		print(b)
	else:
		print(a)
