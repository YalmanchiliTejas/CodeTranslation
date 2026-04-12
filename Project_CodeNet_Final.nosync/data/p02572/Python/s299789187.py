n = int(input())
A = tuple(map(int, input().split()))
from itertools import accumulate
AA = [0] + list(accumulate(A))
mod = 10**9+7

ans = 0
for i in range(n):
    ans += A[i] * (AA[-1]-AA[i+1]) % mod
    ans %= mod
print(ans)