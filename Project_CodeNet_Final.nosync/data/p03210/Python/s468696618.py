# -*- coding: utf-8 -*-
from sys import stdin

s_in = lambda: stdin.readline()[:-1]  # s = s_in()
d_in = lambda: int(stdin.readline())  # N = d_in()
ds_in = lambda: list(map(int, stdin.readline().split()))  # List = ds_in()

X = d_in()

if X in [3, 5, 7]:
    print('YES')
else:
    print('NO')
