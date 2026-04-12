#!/usr/bin/env python3
n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
if n % 2 == 0:
    print(2 * (sum(a[n // 2 :]) - sum(a[: n // 2])) - a[n // 2] + a[n // 2 - 1])
else:
    daishou = 2 * (sum(a[n // 2 :]) - sum(a[: n // 2])) - a[n // 2] - a[n // 2 + 1]
    shoudai = (
        2 * (sum(a[1 + n // 2 :]) - sum(a[: 1 + n // 2])) + a[n // 2] + a[n // 2 - 1]
    )
    print(max(daishou, shoudai))

