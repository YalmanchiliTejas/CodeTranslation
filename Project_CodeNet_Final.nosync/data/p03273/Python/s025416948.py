import numpy as np

H, W = map(int, input().split())
A = np.array([list(input()) for _ in range(H)])

delete_row = []
for i in range(H):
    if '#' not in A[i, :]:
        delete_row.append(i)

delete_column = []
for j in range(W):
    if '#' not in A[:, j]:
        delete_column.append(j)

ans = np.delete(np.delete(A, delete_row, 0), delete_column, 1)

for i in range(len(ans[:, 0])):
    print(''.join(ans[i, :]))