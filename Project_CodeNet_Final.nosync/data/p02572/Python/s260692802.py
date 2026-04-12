N = int(input())
A = list(map(int, input().split()))
MOD = 10**9+7

SU = [0] * (len(A)+1)

for i in range(N):
    SU[i+1] = SU[i] + A[i]

ans = 0
for i in range(N):
    ans += A[i] * (SU[N]-SU[i+1]) % MOD

print(ans%MOD)