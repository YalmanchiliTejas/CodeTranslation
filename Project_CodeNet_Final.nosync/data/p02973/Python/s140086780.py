import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
a = [int(input()) for _ in range(n)]

s = deque([a[0]])

from bisect import bisect_left

for i in a[1:]:
    if i <= s[0]:
        s.appendleft(i)
    else:
        s[bisect_left(s, i) - 1] = i

# print(s)
print(len(s))
