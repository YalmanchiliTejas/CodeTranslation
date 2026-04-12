import decimal

from math import ceil


def solve(k, a, b):
    if k <= a:
        return 1
    if a <= b:
        return -1
    ka = decimal.Decimal(k - a)
    ab = decimal.Decimal(a - b)
    return ceil(ka / ab) * 2 + 1


print(solve(*map(int, input().split())))
