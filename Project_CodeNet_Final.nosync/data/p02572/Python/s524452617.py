MOD = 1000000007
N = int(input())
A = list(map(int, input().split()))
c = 0
S = 0
for a in A:
  S += a % MOD
  S %= MOD
for i in range(N):
    c += (A[i] % MOD) * ((S - A[i] % MOD) % MOD)
    c %= MOD
mod = pow(2, -1, 1000000007)
c = c * mod
c %= MOD
print(int(c))