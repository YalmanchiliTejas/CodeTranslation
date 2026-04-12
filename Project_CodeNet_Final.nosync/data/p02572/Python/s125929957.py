N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

ruiseki = [0 for _ in range(N+5)]
for i in range(N):
    ruiseki[i+1] = ruiseki[i] + A[i]

ans = 0
for i in range(N):
    ans += A[i] * (ruiseki[N] - ruiseki[i+1])
    ans %= mod

print(ans)