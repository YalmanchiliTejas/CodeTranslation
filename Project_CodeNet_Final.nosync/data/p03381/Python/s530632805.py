import numpy as np

N = int(input())
X = np.array(list(map(int, input().split(' '))))

rank = np.argsort(X)
irank = {k: v for v, k in enumerate(rank)}

for i in range(N):
    if irank[i] < N//2:
        print(X[rank[N//2]])
    else:
        print(X[rank[N//2 - 1]])

