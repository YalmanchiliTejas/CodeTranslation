from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import *
from bisect import *
from heapq import *

def read():
  return int(input())
 
def reads():
  return [int(x) for x in input().split()]

N = read()
A = reads()

ls = deque()
rev = False

for a in A:
  if rev:
    ls.appendleft(a)
  else:
    ls.append(a)
  rev = not rev

if rev:
  ls.reverse()

print(" ".join(str(x) for x in ls))
