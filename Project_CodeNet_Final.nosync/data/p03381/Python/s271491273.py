import numpy as np
N = int(input())
X = list(map(int, input().split()))

sx = np.sort(X)
for i in range(N):
    if X[i] >= sx[N//2]:
        print(sx[N//2-1])
    else:
        print(sx[N//2])