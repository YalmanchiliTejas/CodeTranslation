#!/usr/bin/python3
# -*- coding:utf-8 -*-

from copy import deepcopy

def main():
  n = int(input())  
  la = sorted([int(input()) for _ in range(n)])
  
  lo = deepcopy(la)
  ind = 0
  def f(la, ind):
    lx = []
    while len(la) > 0:
      lx.append(la.pop(ind))
      ind = -1 if ind == 0 else 0
    ls = ([abs(lx[i] - lx[i-1]) for i in range(len(lx))])
    return sum(ls)-min(ls)
  print(max(f(deepcopy(la), 0), f(deepcopy(la), -1)))

  
if __name__=='__main__':
  main()

