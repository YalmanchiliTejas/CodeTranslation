import sys
from collections import deque
from bisect import bisect_left

input = sys.stdin.readline

def f(n):
    r = deque()
    for _ in range(n):
        a = int(input())
        i = bisect_left(r, a)
        if i:
            r[i - 1] = a
        else:
            r.appendleft(a)
    print(len(r))

n = int(input())
f(n)
