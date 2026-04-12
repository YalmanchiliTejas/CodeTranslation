import sys
import math
import copy
import queue
input = sys.stdin.readline
def LI(): return [int(x) for x in input().split()]
INF = 10**15
DD = ((1,0),(0,1),(-1,0),(0,-1))
S = input()
if 'A' in S and 'B' in S:
    print ('Yes')
else:
    print ('No')
