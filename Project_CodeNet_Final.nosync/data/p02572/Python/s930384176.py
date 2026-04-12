from itertools import accumulate


N, *A = map(int, open(0).read().split())
MOD = 1_000_000_007

acc = list(accumulate(A, initial=0))
ans = 0
for i in range(1, N):
    ans += A[i - 1] * (acc[N] - acc[i])
    ans %= MOD
print(ans)
