N = int(input())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

p = sum(A)

ans = 0
for i in range(N):
    p -= A[i]
    ans += (A[i] * p) % MOD
    ans %= MOD

print(ans)
