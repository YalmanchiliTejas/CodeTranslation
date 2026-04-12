from sys import stdin
import numpy as np

# N = int(stdin.readline().rstrip().split()[0])
# A = [int(x) for x in stdin.readline().rstrip().split()]
N, X = [int(x) for x in stdin.readline().rstrip().split()]


def func(n, x):
  # 動的計画法?
  if x==0:
    return 0
  elif x==1 and n==0:
    return 1
  elif x==4*2**n-3:
    return 2*2**n-1
  elif x <= 4*2**(n-1)-3 +1:
    return func(n-1, x-1)
  else:
    return  func(n-1, 2*2**n-3) + func(n-1,x-2*2**n+1) +1
print(func(N, X))