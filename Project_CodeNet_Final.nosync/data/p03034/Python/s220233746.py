import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import numpy as np

N = int(readline())
S = np.array(read().split(),np.int64)

answer = 0
for d in range(1,N):
    n = (N-1)//d
    if (N-1)%d == 0:
        n = ((N-1)//d+1)//2
    if n <= 1:
        continue
    x = (S[d:d*n:d] + S[N-1-d:N-1-d*n:-d]).cumsum().max()
    if answer < x:
        answer = x

print(answer)