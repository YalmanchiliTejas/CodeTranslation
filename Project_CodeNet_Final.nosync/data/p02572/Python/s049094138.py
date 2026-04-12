N = int(input())
A = [int(d) for d in input().split()]

MOD = int(1e9+7)

A_cum = [0]
for i in range(N):
    A_cum.append((A_cum[-1] + A[i]) % MOD)

ans = 0
for i in range(N-1):
    t = (A[i] * (A_cum[-1] - A_cum[i+1]) % MOD ) % MOD
    ans = (t + ans)% MOD

print(ans)