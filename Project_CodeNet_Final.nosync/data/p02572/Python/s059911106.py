import sys
from itertools import accumulate
n = int(sys.stdin.buffer.readline())
a = list(map(int, sys.stdin.buffer.readline().split()))
aa = list(accumulate(a))
MOD = 10**9+7
ans = 0
for i in range(n):
    ans += a[i]*(aa[n-1] - aa[i])
print(ans%MOD)
