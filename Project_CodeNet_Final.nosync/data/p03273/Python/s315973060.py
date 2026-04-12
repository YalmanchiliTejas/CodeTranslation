import numpy as np

H,W = list(map(int, input().split()))

mat = np.zeros((H, W))
original_mat = []

removed_line = []
removed_column = []

for i in range(H):
    row = input()
    line = []
    for j, c in enumerate(row):
        if c == "#":
            mat[i, j] = 1

    # print(mat[i,:])
    if np.sum(mat[i,:]) == 0:
        removed_line.append(i)
    else:
        original_mat.append(row)

for i in range(W):
    # print(mat[:,i])
    if np.sum(mat[:,i]) == 0:
        removed_column.append(i)

# print(removed_line)
# print(removed_column)

for row in original_mat:
    for i, c in enumerate(row):
        if i not in removed_column:
            print(c, end="")
    print("\n", end="")
