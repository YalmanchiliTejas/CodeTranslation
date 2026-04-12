n = int(input())
a = list(map(int, input().split()))

from itertools import accumulate
cumsum = list(accumulate(a[::-1]))[::-1]

MOD = 10**9+7
ans = 0
for i,A in enumerate(a[:-1]):
    ans += A * cumsum[i+1]
    ans = ans % MOD
print(ans)