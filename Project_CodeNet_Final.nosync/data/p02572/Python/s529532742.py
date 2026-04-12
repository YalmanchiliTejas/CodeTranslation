from itertools import accumulate
n = int(input())
A = list(map(int, input().split()))
MOD = 10**9+7
Acum = list(accumulate(A))

ans = 0
for i, a in enumerate(reversed(A[1:])):
    ans += Acum[n-i-2]*a
    ans %= MOD
print(ans)