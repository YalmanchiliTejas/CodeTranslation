#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math

al = [0, 5] + [0] * 49
bl = [0, 3] + [0] * 49


def solve2(ans, x, idx, cnt):
    if idx == 1:
        if x >= 5:
            return ans + 3
        return ans + (0, 0, 1, 2, 3, 3)[x]
    if x >= al[idx - 1] + 1:
        ans += bl[idx - 1]
        x -= al[idx - 1] + 1
        if x >= 1:
            ans += 1
            x -= 1
    else:
        x -= 1
        if x <= 0:
            return ans
    return solve2(ans, x, idx - 1, cnt)


def solve(n, x):
    for i in range(2, n + 1):
        al[i] = al[i - 1] * 2 + 3
        bl[i] = bl[i - 1] * 2 + 1
    ans = solve2(0, x, n, 0)
    print(ans)


if __name__ == "__main__":
    n, x = map(int, input().split())
    solve(n, x)
