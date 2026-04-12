#!/usr/bin/env python

from sys import stdin, stderr

DPL = [0] * 56
DPP = [0] * 56

def F(n, x):
   if x == 0:
      return 0

   if x == 1:
      return 1 if n == 0 else 0

   if x == DPL[n]:
      return DPP[n]

   if x == 1 + DPL[n-1] + 1:
      return DPP[n-1] + 1
   elif x > 1 + DPL[n-1] + 1:
      return DPP[n-1] + 1 + F(n-1, x - (1 + DPL[n-1] + 1))
   else:
      return F(n-1, x-1)

def main():
   N, X = map(int, stdin.readline().split())

   DPL[0] = 1
   DPP[0] = 1
   for n in xrange(1, N+1):
      DPL[n] = 2*DPL[n-1] + 3
      DPP[n] = 2*DPP[n-1] + 1

   res = F(N, X)
   print(res)

   return 0

if __name__ == '__main__': main()
