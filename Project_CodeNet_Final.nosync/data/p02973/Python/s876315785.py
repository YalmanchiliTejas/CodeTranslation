#  --*-coding:utf-8-*--

import bisect

N = int(input())
A = [int(input()) for _ in range(N)]

Q = []
x = 0

for a in A:
    idx = bisect.bisect_right(Q, -a)

    if idx >= len(Q):
        x += 1
        Q.append(-a)
    else:
        Q[idx] = -a

print(x)
    
        
