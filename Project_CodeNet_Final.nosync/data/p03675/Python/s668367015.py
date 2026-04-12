import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import deque

N,*A = map(int,read().split())

B = deque()
reverse = False
for x in A:
    if reverse:
        B.appendleft(x)
    else:
        B.append(x)
    reverse = not reverse

B = list(B)
if reverse:
    B = B[::-1]

print(' '.join(map(str,B)))