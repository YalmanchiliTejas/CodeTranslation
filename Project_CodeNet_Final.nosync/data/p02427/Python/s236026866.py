import heapq
from collections import deque
from enum import Enum
import sys
import math
from _heapq import heappush, heappop
import copy

BIG_NUM = 2000000000
MOD = 1000000007
EPS = 0.000000001


SIZE = 19

POW = [1]*SIZE
for i in range(1,SIZE):
    POW[i] = POW[i-1]*2

N = int(input())

print("0:")

index = 1
for state in range(1,POW[N]):
    print("%d:"%(index),end="")
    for loop in range(N):
        if state & POW[loop] != 0:
            print(" %d"%(loop),end="")
    print()
    index += 1
