N = int(input())
A = [int(v) for v in input().split()]
MOD = int(1e9 + 7)

S = sum(A)
SQ = S * S
IS = sum(a*a for a in A)

print(((SQ - IS) // 2) % MOD)