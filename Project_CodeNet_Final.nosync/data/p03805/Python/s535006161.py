import numpy as np
N, M = list(map(int, input().split()))
mtr = np.zeros((N, N), dtype=np.bool)
for _ in range(M):
    a, b = list(map(int, input().split()))
    mtr[a-1][b-1] = 1
    mtr[b-1][a-1] = 1
def v(i=0):
    return [_i for _i, _j in enumerate(mtr[i]) if _j]
def search_path(node, done):
    _d = done.copy()
    _d[node] = True
    if False not in _d:
        return [True]
    flag = [False]
    _v = [_i for _i in v(node) if not _d[_i]]
    if _v == []:
        return [False]
    return(np.concatenate([search_path(_i, _d) for _i in _v]))
print(list(search_path(0, np.zeros(N, dtype=np.bool))).count(True))