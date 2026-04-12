import itertools

N = int(input())
A = list(map(int, input().split()))
MOD = 10**9+7

A.sort()
ac = list(itertools.accumulate(A))

ans = 0
for i in range(N):
    ans += A[i]*(ac[-1]-ac[i])
print(ans % MOD)
