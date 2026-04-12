from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1000000)

(H, W) = reads()
A = []

for _ in range(H):
  A.append(input()+".")
A.append("." * (W+1))

walk = [(0, 0)]

for i in range(H + W - 2):
  (y, x) = walk[-1]
  if A[y][x+1] == "#":
      walk.append((y, x+1))
  elif A[y+1][x] == "#":
      walk.append((y+1, x))
  else:
    print("Impossible"); exit()

if all(A[y][x] == "." for y in range(H) for x in range(W) if not (y, x) in walk):
  print("Possible")
else:
  print("Impossible")
