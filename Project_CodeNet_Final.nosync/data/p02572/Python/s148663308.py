# C - Sum of product of pairs

N = int(input())
A = list(int(a) for a in input().split())
MOD = 10**9 + 7

csA = [0] * (N+1)
for i in range(N):
    csA[i+1] = csA[i] + A[i]

ans = 0
for i in range(N-1):
    ans += (A[i] * (csA[N] - csA[i+1])) % MOD
print(ans%MOD)