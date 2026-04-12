# -*- coding:utf-8 -*-
# /usr/bin/python3

from bisect import bisect_left
from collections import deque

def main():
  N = int(input())
  liA = list(map(int, [input() for _ in range(N)]))
  colors = deque([liA[0]])
  for a in liA[1:]:
    if a <= colors[0]:
      colors.appendleft(a)
    else:
      i = bisect_left(colors, a)
      colors[i-1] = a

  print(len(colors))
  pass

if __name__=='__main__':
  main()
