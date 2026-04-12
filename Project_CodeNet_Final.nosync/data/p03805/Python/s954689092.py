from itertools import permutations
import numpy as np
N, M = map(int, input().split(" "))#N頂点M辺
edges = []
for _ in range(M):
    edges += [list(map(int, input().split(" ")))]

count = 0
for line in permutations(np.arange(N - 1) + 2):
    vtxs = [1] + list(line)
    for i in range(N - 1):
        edge = sorted([vtxs[i], vtxs[i + 1]])
        if edge not in edges:
            break
    else:
        count += 1
print(count)