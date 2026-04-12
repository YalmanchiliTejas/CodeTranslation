import math

N = int(input())
A = list(map(int ,input().split()))
MOD = math.floor(1e9+7)

sum = 0
for i in range (N):
    sum += A[i] % MOD

ans = 0
for i in range(N):
    sum -= A[i]
    ans += (A[i] * sum) % MOD

ans = ans % MOD
print(ans)