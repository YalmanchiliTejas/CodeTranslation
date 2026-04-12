n = int(input())
a = list(map(int, input().split()))

MOD = pow(10, 9) + 7

two_inv = pow(2, -1, MOD)

sq = []

for x in a:
    sq.append(x ** 2 % MOD)

s = sum(a) % MOD
s_sq = sum(sq) % MOD

print((pow(s, 2, MOD) - s_sq) * two_inv % MOD)