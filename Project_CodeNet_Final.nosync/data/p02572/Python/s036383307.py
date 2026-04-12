
if __name__ == "__main__":
	MOD = 10 ** 9 + 7
	N=int(input())
	A=list(map(int,input().split()))

	Asum = sum(A) % MOD

	ans = 0
	for n in range(N-1):
		Asum -= A[n]
		ans += ((A[n] * Asum) % MOD)

	print(ans % MOD)
