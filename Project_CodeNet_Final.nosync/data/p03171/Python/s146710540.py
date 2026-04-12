import numpy as np
from numba import njit

N = int(input())
scores = np.array(list(map(int, input().split())), dtype='int64')
dpt = np.full((N, N), -10**18, dtype='int64')

@njit('i8(i8[:],i8[:,:],i8,i8)', cache=True)
def get_max_score(scores, dpt, i, j):
    if i == j:
        dpt[i][j] = scores[i]
        return scores[i]
    else:
        if dpt[i][j] != -10**18:
            return dpt[i][j]
        result = max(scores[i] - get_max_score(scores, dpt, i+1, j), scores[j] - get_max_score(scores, dpt, i, j-1))
        dpt[i][j] = result
        return result

print(get_max_score(scores, dpt, 0, len(scores)-1))
