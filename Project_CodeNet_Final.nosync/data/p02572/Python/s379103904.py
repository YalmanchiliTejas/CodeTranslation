(N,) = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

S = sum(A)
MOD = 10 ** 9 + 7
print(((S * S - sum(x * x for x in A)) // 2) % MOD)

