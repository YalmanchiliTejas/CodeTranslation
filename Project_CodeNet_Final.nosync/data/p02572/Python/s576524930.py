from itertools import accumulate

MOD = 10 ** 9 + 7
N, *A = map(int, open(0).read().split())

B = list(accumulate(A)) # cumsum

ans = 0
for i in range(N-1):
    ans += A[i] * (B[-1] - B[i]) % MOD
    ans %= MOD
print(ans)