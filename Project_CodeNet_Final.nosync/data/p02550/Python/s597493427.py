from collections import Counter
import sys
import math
from functools import cmp_to_key

sys.setrecursionlimit(10 ** 6)

mod = 1000000007
inf = int(1e18)


def main():
    n, x, m = map(int, input().split())
    s = [0] * int(1e5 + 10)
    dp = [x]
    s[x] = 1
    a = x
    for i in range(int(1e5+10)):
        a = a * a % m
        if s[a]:
            first = dp[:dp.index(a)]
            dp = dp[dp.index(a):]
            break
        else:
            dp.append(a)
            s[a] = 1
    ans = sum(first[:n])
    n -= len(first)
    if n <= 0:
        print(ans)
        return
    cyc = sum(dp)
    if a == 0:
        print(ans + sum(dp[:n]))
        return
    ans += cyc * (n // len(dp))
    for i in range(n % len(dp)):
        ans += dp[i]
    print(ans)


main()
