import sys
from itertools import accumulate
input = lambda: sys.stdin.readline().rstrip('\r\n')

mod = int(pow(10, 9) + 7)

n = int(input())
a = list(map(int, input().split()))
x = a[:]
b = a[::-1][:]
b = list(accumulate(b))
a = b[::-1][:]
ans = 0
for i in range(n - 1):
    ans += (x[i] * a[i + 1]) % mod
print(ans % mod)