import numpy as np
import math

# K = int(input())
# A, B = map(int, input().split())
# A = list(map(int, input().split()))

N, M = map(int, input().split())

edges = []
E = np.zeros((N, N), dtype=int)

for m in range(M):
    s, t = map(int, input().split())
    s = s - 1
    t = t - 1
    E[s][t] = 1
    E[t][s] = 1

# print('edge=', E)


def count(path, E):
    if len(path) == N:
        return 1
    else:
        edges = []
        cur = path[-1]
        ret = 0
        for n in range(N):
            if E[cur][n] == 1 and n not in path:
                npath = path + [n]
                ret += count(npath, E)
        return ret

ret = count([0], E)
print(ret)
