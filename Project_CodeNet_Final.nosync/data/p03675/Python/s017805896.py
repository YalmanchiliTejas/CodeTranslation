# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

n,*a = map(int,read().split())


from collections import deque

q = deque()

flag = 0
for ai in a:
    if flag==0:
        q.append(ai)
    else:
        q.appendleft(ai)
    flag ^= 1

q = list(q)
#print(q)
if flag==0:
    print(*q)
else:
    print(*q[::-1])







