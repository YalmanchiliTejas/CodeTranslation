# coding: utf-8
# Your code here!
from collections import deque

n = int(input())
a = list(map(int, input().split()))
que = deque()

for i in range(n):
    if i % 2 == 0:
        que.append(a[i])
    else:
        que.appendleft(a[i])
        
if len(que) % 2 != 0:
    for j in range(n):
        print(que.pop(), end = " ")
else:
    for k in range(n):
        print(que.popleft(), end = " ")