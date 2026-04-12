N = int(input())
A = list(map(int,input().split()))

MOD = 10**9 + 7

S1, S2 = 0, 0
for a in A:
    S1 += a
    S2 += a * a % MOD
    S1 %= MOD
    S2 %= MOD

print(((S1*S1%MOD-S2+MOD) % MOD) * pow(2,MOD-2,MOD) % MOD)

