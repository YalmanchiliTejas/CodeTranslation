mod = 10 ** 9 + 7

N, *A = map(int, open(0).read().split())

S1 = sum(A)
S2 = sum(a * a for a in A)

print((S1 ** 2 - S2) // 2 % mod)