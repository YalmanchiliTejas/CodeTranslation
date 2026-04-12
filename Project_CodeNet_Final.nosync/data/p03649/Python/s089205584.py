import sys
from heapq import *
from math import ceil
input = sys.stdin.readline
N = int(input())
H = []
for a in list(map(int, input().split())):
    heappush(H,-a)
off = 0
while True:
    x = heappop(H)
    a = -x+off
    if a<=N-1: print(off); exit()
    cnt = ceil(max(a-(N-1), 0)/(N+1))
    a -= cnt*(N+1)
    heappush(H,off-a)
    off += cnt