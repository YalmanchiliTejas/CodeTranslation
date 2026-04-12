#!/usr/bin/env python
# -*- coding: utf-8 -*-

N = int(input())
S = input()
K = int(input())


def r(c):
    if c == S[K - 1]:
        return c
    else:
        return '*'


print(''.join(map(r, S)))
