import bisect
import os
import sys
from collections import deque

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(2147483647)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7

N = int(sys.stdin.readline())
A = [int(sys.stdin.readline()) for _ in range(N)]

seq = deque()
for a in A:
    i = bisect.bisect_left(seq, a)
    if i == 0:
        seq.appendleft(a)
    else:
        seq[i - 1] = a
        while i < len(seq) and seq[i - 1] > seq[i]:
            seq[i], seq[i - 1] = seq[i - 1], seq[i]
            i += 1
print(len(seq))
