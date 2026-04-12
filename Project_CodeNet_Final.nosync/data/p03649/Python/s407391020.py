#!/usr/bin/env python
# -*- coding: utf-8 -*-
def main():
  N = int(raw_input())
  A = map(lambda s: int(s) - N + 1, raw_input().split())
  K = 0
  while True:
    c = []
    for i in xrange(N):
      if A[i] > 0:
        c.append(i)
    if not c:
      break
    s = 0
    for i in c:
      k = (A[i] + (N - 1)) / N
      A[i] -= k * (N + 1)
      s += k
    for i in xrange(N):
      A[i] += s
    K += s
  print K

main()