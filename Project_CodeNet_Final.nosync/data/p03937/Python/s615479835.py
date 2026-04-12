import sys
import itertools
# import numpy as np
import time
import math
from heapq import heappop, heappush
from collections import defaultdict
from collections import Counter
from collections import deque
from itertools import permutations
sys.setrecursionlimit(10 ** 7)
 
INF = 10 ** 18
MOD = 10 ** 9 + 7
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# map(int, input().split())
H, W = list(map(int, input().split()))
A = [input() + '.' for _ in range(H)]
A.append('.' * (W + 1))

cnt = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            cnt += 1
if cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")

# cur = (0, 0)
# while True:
#     x, y = cur
#     if x == W - 1 and y == H - 1:
#         print("Possible")
#         break
#     nx1, ny1 = x + 1, y
#     nx2, ny2 = x, y + 1
#     if A[ny1][nx1] == '#' and A[ny2][nx2] == '#':
#         print("Impossible")
#         break
#     if A[ny1][nx1] == '#':
#         cur = (nx1, ny1)
#     elif A[ny2][nx2] == '#':
#         cur = (nx2, ny2)
#     else:
#         print("Impossible")
#         break


