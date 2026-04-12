def resolve():
	N = int(input())
	A = list(map(int, input().split()))
	S = sum(A)
	res = 0
	v = 10**9+7
	for i in range(N-1):
		S -= A[i]
		res += A[i] * S
	print(res%v)
resolve()