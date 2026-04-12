#!/usr/bin/env python3
# -*- coding:utf-8 -*-

P = True
B = False
lenP = lambda x: 2*x + 1
lenB = lambda x: 2*x + 2
lenS = lambda x: 2*x + 3

def main():
  n, x = map(int, input().split())
  _next = lambda burger: [B] + burger + [P] + burger + [B]
  burger = [P]
  Pn = {0:1}
  Bn = {0:0}
  Sn = {0:1}
  for i in range(n):
    Pn[i+1] = lenP(Pn[i])
    Bn[i+1] = lenB(Bn[i])
    Sn[i+1] = lenS(Sn[i])
  _sum = 0
  middle = int((Sn[n] + 1)/2)
  for i in list(range(1, n+1))[::-1]:
    if middle == x:
      _sum += int(Pn[i-1])
      break
    elif middle < x:
      _sum += Pn[i-1] + 1
      middle += int((Sn[i-1]+1)/2)
    else:
      middle -= int((Sn[i-1]+1)/2)
      pass
  if middle <= x:
    _sum += 1

  print(_sum)

  pass

if __name__=='__main__':
  main()