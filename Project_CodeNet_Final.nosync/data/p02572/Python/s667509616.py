N = int(input())
A = list(map(int, input().split()))
ans = 0
MOD = 10 ** 9 + 7
s = 0
for i in range(N - 1):
	s += A[i]
	tmp = s * A[i + 1]
	ans += (tmp % MOD)
print(ans % MOD)
