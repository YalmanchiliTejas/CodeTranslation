"""C."""

import sys

input = sys.stdin.readline  # noqa: A001

n = int(input())
a = list(map(int, input()[:-1].split(' ')))

MOD_VALUE = 10**9 + 7
result = 0

a_sum = sum(a)

for v in a:
    result += v * (a_sum - v)
    a_sum -= v

if result < MOD_VALUE:
    print(result)
else:
    print(result % MOD_VALUE)
