import numpy as np

h, w = map(int, input().split())
A = np.array([list(input()) for i in range(h)])

ans = []
for i in range(h):
    a = ''
    for j in range(w):
        if '#' in A[i] and '#' in A[:, j]:
            a += A[i][j]
    if a != '':
        ans.append(a)

for a in ans:
    print(a, sep='')
