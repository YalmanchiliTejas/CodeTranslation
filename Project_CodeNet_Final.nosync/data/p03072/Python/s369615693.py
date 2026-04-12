# -*- coding: utf-8 -*-
import sys


def get_num():
    return int(input())


def get_nums(n):
    res = [0 for _ in range(n)]
    for i in range(n):
        res[i] = int(input())
    return res


def get_numbers():
    return map(int, input().split())

n = get_num()
h = list(get_numbers())

highest = 0
ans = 0
for height in h:
    if height >= highest:
        highest = height
        ans += 1

print(ans)