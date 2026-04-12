#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from itertools import chain
from functools import reduce
from collections import OrderedDict, Counter, deque
import operator

IS = lambda: int(input())
IA = lambda: [int(x) for x in input().split()]

_ = IS()
H = IA()

ans = 0
cur = -1
for h in H:
    if cur <= h:
        cur = h
        ans += 1
print(ans)