# coding: utf-8
# Your code here!

from collections import deque

N = int(input())
a = deque(list(map(int, input().split())))
tmp = 0
ctr = 0

for i in range(N):
    tmp = a.pop()
    if a == deque([]):
        ctr += 1
    elif max(a) <= tmp:
        ctr += 1
print(ctr)
