MOD = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

S = 0
T = 0

for i in range(N):
    S += A[i] **2
    T += A[i]
    S %= MOD
    T %= MOD

print((T**2 - S) * pow(2, MOD - 2, MOD) % MOD)