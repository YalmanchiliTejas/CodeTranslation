#!/usr/local/bin python
# -*- coding: utf-8 -*-
#
# ~/PycharmProjects/atcoder/B-GridCompression.py
#
import numpy as np

h, w = map(int, input().split())
a = []
for i in range(h):
    a_i = input()
    if a_i != '.' * w:
        a.append(list(a_i))

b = [""] * len(a)

for j in range(w):
    for i in range(len(a)):
        if a[i][j] == "#":
            break

    if a[i][j] == "#":
        for ii in range(len(a)):
            b[ii] = b[ii] + a[ii][j]

for i in range(len(a)):
    print(b[i])

