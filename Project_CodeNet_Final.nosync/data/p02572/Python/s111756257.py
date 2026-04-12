from itertools import accumulate
MOD = 10**9 + 7


N = int(input())
A = list(map(int, input().split()))
A_cumsum = list(accumulate(A))

ans = 0
for i in range(N-1):
    ans += A[i] * (A_cumsum[-1] - A_cumsum[i]) % MOD

print(ans % MOD)