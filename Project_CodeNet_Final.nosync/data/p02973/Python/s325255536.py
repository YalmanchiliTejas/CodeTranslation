from sys import stdin
from bisect import bisect_left
from collections import deque

n = int(input())
a = [int(stdin.readline()) for _ in range(n)]

l = deque()

for i in range(n):
  n = bisect_left(l, a[i])
  if n == 0:
    l.appendleft(a[i])
  else:
    l[n - 1] = a[i]

print(len(l))


