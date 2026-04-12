n = int(input())
A = [*map(int, input().split())]
S = [0] * (n+1)
for i in range(n): S[i+1] = S[i] + A[i]
MOD = (10**9)+7
ans = 0
for i in range(n): ans = (ans + A[i] * (S[-1] - S[i+1])) % MOD
print((ans + MOD) % MOD)
