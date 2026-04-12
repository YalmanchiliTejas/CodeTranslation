from itertools import accumulate


N = int(input())
A = list(map(int, input().split()))
MOD = 1_000_000_007
acc = list(accumulate(A, initial=0))

ans = 0
for i in range(N):
    ans += A[i] * (acc[N] - acc[i + 1])
    ans %= MOD
print(ans)
