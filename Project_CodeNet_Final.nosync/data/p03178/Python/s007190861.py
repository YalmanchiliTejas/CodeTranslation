import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

import numpy as np
from numpy.fft import rfft, irfft
MOD = 10 ** 9 + 7
K = [int(x) for x in input().rstrip()]
L = len(K)
D = int(input())

def convolve_ones(x,arr):
    # 0,1,...,x-1
    after = np.zeros(D+x,dtype=np.int64)
    for i in range(x):
        after[i:i+D] += arr
    for i in range(D,D+x):
        after[i%D]+= after[i]
    return after[:D] % MOD

# d桁以下、自由に使った場合の余りごとの個数。0を含めて数えておく
full = [np.zeros(D, dtype=np.int64)]
full[0][0] = 1
for d in range(1,L):
    full.append(convolve_ones(10,full[-1]))

dist = np.zeros(D+D, dtype=np.int64)

cumsum = 0
for i,x in enumerate(K):
    arr = convolve_ones(x, full[L-i-1])
    dist[cumsum:cumsum+D] += arr
    cumsum += x
    cumsum %= D
dist[cumsum] += 1 # 全部そのまま使う

answer = dist[::D].sum() - 1 # 0除外
answer %= MOD
print(answer)