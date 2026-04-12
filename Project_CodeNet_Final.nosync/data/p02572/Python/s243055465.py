n = int(input())
A = [*map(int, input().split())]
MOD = (10**9)+7
S = [0] * (n+1)
for i in range(n): S[i+1] = S[i] + A[i]
ans = 0
for i in range(n): ans = (ans + A[i] * (S[-1] - S[i+1])) % MOD
ans = (ans + MOD) % MOD
print(ans)
