N = int(input())
X = list(map(int,input().split()))
Y = sorted(X)
x_n1 = Y[N//2 - 1]
x_n2 = Y[N//2]

for i in range(N):
	if X[i] <= x_n1:
		print(x_n2)
	else:
		print(x_n1)