import math
from fractions import Fraction as frac

MOD = 1000000007

def solve(case_no):
    n = int(input())
    a = list(map(int, input().split()))
    ps = [a[0]]
    for i in range(1, n):
        ps.append(ps[i - 1] + a[i])
    ans = 0
    for i in range(n - 2, -1, -1):
        ans += a[i + 1] * ps[i]
        ans %= MOD
    print(int(ans))

t = 1
# t = int(input())
for i in range(1, t + 1):
    solve(i)
