from itertools import accumulate


N, *A = map(int, open(0).read().split())
MOD = 1_000_000_007
acc = list(accumulate(A, initial=0))

ans = 0
for i in range(N - 1):
    ans += A[i] * (acc[N] - acc[i + 1])
    ans %= MOD
print(ans)
