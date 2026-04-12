# /user/bin/python
# -*- coding: utf-8 -*-
import sys 

h,w = map(int, sys.stdin.readline().rstrip().split())
As = []
for i in range(h):
  As.append(str(sys.stdin.readline().rstrip()))

cnt_h = [0] * h
cnt_w = [0] * w

for i in range(h):
  for j in range(w):
    if As[i][j] == '.':
      cnt_h[i] += 1
      cnt_w[j] += 1

idx_h = []
for i in range(h):
  if cnt_h[i] < w:
    idx_h.append(i)

idx_w = []
for i in range(w):
  if cnt_w[i] < h:
    idx_w.append(i)

for i in idx_h:
  for j in idx_w:
    print(As[i][j], end="")
  print()