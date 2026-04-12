MOD = 10 ** 9 + 7

N = int(input())
A = list(map(int, input().split()))

rui = [A[0]] * N
for i in range(1, N):
	rui[i] = (rui[i - 1] + A[i]) % MOD
ans = 0
for i in range(1, N):
	ans = (ans + A[i] * rui[i - 1]) % MOD
print(ans)