import numpy as np

h, w = tuple(map(int, input().split()))
matrix = np.zeros((h, w), dtype=bool)
for i in range(h):
    row = np.array(list(input()))
    matrix[i, :] = row == "."

for i in range(h)[::-1]:
    if np.all(matrix[i, :]):
        matrix = np.delete(matrix, i, 0)

for i in range(w)[::-1]:
    if np.all(matrix[:, i]):
        matrix = np.delete(matrix, i, 1)

matrix = np.where(matrix, ".", "#")
for row in matrix:
    for e in row:
        print(e, end="")
    print()
