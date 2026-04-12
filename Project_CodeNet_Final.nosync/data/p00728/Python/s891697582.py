# -*- coding: utf-8 -*-
from itertools import accumulate
def inpl(): return map(int, input().split())

N = int(input())

while N:
    tmp = sorted([int(input()) for _ in range(N)])
    print(sum(tmp[1:-1])//(N-2))

    N = int(input())
