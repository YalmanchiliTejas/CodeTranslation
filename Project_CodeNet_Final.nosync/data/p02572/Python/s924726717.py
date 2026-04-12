MOD = 10 ** 9 + 7

N = int(input())
A = list(map(int, input().split()))
s = sum(A)

res = 0
for v in A:
	res = (res + v * (s-v)) % MOD

print(res * pow(2, MOD-2, MOD) % MOD)
