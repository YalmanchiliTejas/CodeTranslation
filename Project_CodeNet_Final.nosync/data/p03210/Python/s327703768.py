# -*- coding: utf-8 -*-
import math
import sys

def solve(i):
  if i in [3, 5, 7]:
    return "YES"
  else:
    return "NO"

if __name__ == "__main__":
    x = int(sys.stdin.readline().rstrip())
    print(solve(x))