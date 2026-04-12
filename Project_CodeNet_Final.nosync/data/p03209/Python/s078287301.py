#!/usr/bin/env python
# -*- coding: utf-8 -*-

al = [0, 5] + [0] * 49
bl = [0, 3] + [0] * 49


def solve2(ans, x, idx):
    if idx == 1:
        if x >= 5:
            return ans + 3
        if x <= 0:
            return ans
        return ans + (0, 0, 1, 2, 3, 3)[x]
    if x >= al[idx - 1] + 1:
        ans += bl[idx - 1]
        x -= al[idx - 1] + 1
        if x >= 1:
            ans += 1
            x -= 1
    else:
        x -= 1
    return solve2(ans, x, idx - 1)


def solve():
    n, x = map(int, input().split())
    for i in range(2, n + 1):
        al[i] = al[i - 1] * 2 + 3
        bl[i] = bl[i - 1] * 2 + 1
    print(solve2(0, x, n))


if __name__ == "__main__":
    solve()
