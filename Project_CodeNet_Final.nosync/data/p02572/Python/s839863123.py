N = int(input())
A = list(int(a) for a in input().split())
MOD = 10**9 + 7
S = sum(A)

ans = 0
for i in range(N-1):
    S -= A[i]
    ans += (A[i] * S) % MOD
print(ans%MOD)