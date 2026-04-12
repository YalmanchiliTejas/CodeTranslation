import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import numpy as np
import itertools

K = list(map(int,readline().rstrip().decode('utf-8')))
D = int(read())

MOD = 10**9 + 7

Kcum = list(itertools.accumulate(K))

x = np.zeros(D,np.int64)
x[0] = 1
answer = 0
for kc,k in zip(Kcum[::-1],K[::-1]):
    for i in range(kc-k,kc):
        rest = (-i)%D
        answer += x[rest]
    y = np.zeros(D+10,np.int64)
    y[:D] = x
    y[10:] -= x
    np.cumsum(y,out=y) # 1-xで割る
    for d in range(D,D+10):
        y[d%D] += y[d]
    x = y[:D] % MOD

answer -= 1 # 0
if Kcum[-1]%D==0:
    answer += 1

answer %= MOD
print(answer)