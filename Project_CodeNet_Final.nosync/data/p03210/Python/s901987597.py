# -*- coding: utf-8 -*-
"""
Created on Sun Dec  2 20:06:38 2018

@author: Owner
"""

import collections
import scipy.misc
import sys
import numpy as np
import math
from operator import itemgetter

def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(int(i))
    i += 1
  if n > 1:
    table.append(int(n))
  return table   

"""
N, X = map(int, input().split())

x = [0]*N
x[:] = map(int, input().split())

P = [0]*M
Y = [0]*M
for m in range(M):
    P[m], Y[m] = map(int, input().split())
"""

X = int(input())

if X == 7:
    print('YES')
    sys.exit()
elif X == 5:
    print('YES')
    sys.exit()
elif X == 3:
    print('YES')
    sys.exit()
else:
    print('NO')
    
    