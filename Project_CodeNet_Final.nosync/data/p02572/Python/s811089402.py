# coding:utf-8

import sys
import math
import time
#import numpy as np
import collections
from collections import deque
from collections import Counter
import queue
import copy
import bisect
import heapq
import itertools


sys.setrecursionlimit(10**7)
#N, Q = map(int, input().split())
#G = [list(input()) for i in range(H)]
#INF = V * 10001
#A = [int(i) for i in input().split()]
#AB = [list(map(int, input().split())) for _ in range(K)]

N = int(input())
A = [int(i) for i in input().split()]
ans = 0
MO = 10**9+7
SA = [0]*N
SA[N-1] = A[N-1]
for i in reversed(range(1, N)):
    SA[i-1] = SA[i]+A[i-1]

for i in range(N-1):
    ans += A[i]*SA[i+1]%MO

print(ans%MO)
