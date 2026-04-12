#!/usr/bin/python3
# -*- coding: utf-8 -*-
from bisect import bisect_left
from collections import deque


def solve():
  N = int(input())
  An = [int(input()) for _ in range(N)]
  if N==1:
    return 1
  else:
    ret = deque([An[0]])
    for a in An[1:]:
      idx = bisect_left(ret,a)
      if idx == 0:
        ret.appendleft(a)
      else:
        ret[idx-1] = a
    return len(ret)


print(solve())