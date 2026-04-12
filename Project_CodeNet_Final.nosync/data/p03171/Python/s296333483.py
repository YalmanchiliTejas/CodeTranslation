import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import deque

N,*A = map(int,read().split())

B = deque()
for a in A:
    B.append(a)
    while True:
        if len(B) < 3:
            break
        x,y,z = B[-3],B[-2],B[-1]
        if x<=y>=z:
            B.pop()
            B.pop()
            B[-1] = x+z-y
            continue
        break

get = []
while B:
    if B[0] > B[-1]:
        x = B.popleft()
    else:
        x = B.pop()
    get.append(x)

answer = sum(get[::2]) - sum(get[1::2])

print(answer)