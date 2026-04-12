import sys
import heapq
import math
import fractions
import bisect
import itertools
from collections import Counter
from collections import deque
from operator import itemgetter
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

h,w=mp()
ans=0
for i in range(h):
    ans+=input().count("#")
if ans==h+w-1:
    print("Possible")
else:
    print("Impossible")