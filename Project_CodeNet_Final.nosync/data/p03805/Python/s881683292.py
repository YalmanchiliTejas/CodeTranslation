N, M = list(map(int, input().split()))
G = {}
for i in range(0,M):
    a, b = list(map(int, input().split()))
    if a in G:
        G[a] += [b]
    else:
        G[a] = [b]
    if b in G:
        G[b] += [a]
    else:
        G[b] = [a]

from itertools import permutations
import copy
paths = list(map(lambda x: [1] + list(x),list(permutations(range(2,1+N),N-1))))
cnt = 0

for path in paths:
    _G = copy.deepcopy(G)
    flg = 1
    for i in range(1,N):
        if path[i] in _G[path[i-1]]:
            _G[path[i-1]].remove(path[i])
            _G[path[i]].remove(path[i-1])
        else:
            flg = 0
            break
    cnt += flg

print(cnt)