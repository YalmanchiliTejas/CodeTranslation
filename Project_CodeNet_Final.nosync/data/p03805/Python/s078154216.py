import itertools
import numpy as np

N, M = map(int, input().split())
X = [[] for _ in range(M)]
for i in range(M):
    X[i] = list(map(int, input().split()))
permutations_list = list(itertools.permutations([i for i in range(N-1)]))

count = 0
for i in range(len(permutations_list)):
    x = np.argsort(permutations_list[i])
    if [1, x[0]+2] not in X and [x[0]+2, 1] not in X:
        count += 1
        continue
    for j in range(N-2):
        pair = [x[j]+2, x[j+1]+2]
        reverse = list(reversed(pair))
        if pair not in X and reverse not in X:
            count += 1
            break
print(len(permutations_list) -count)