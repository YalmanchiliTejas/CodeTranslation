import numpy as np

H, W = map(int, input().split())
A = np.array([list(input()) for _ in range(H)])

row = [False] * H
column = [False] * W

for h in range(H):
    for w in range(W):
        if A[h, w] == "#":
            break
        if w == W-1:
            row[h] = True

for w in range(W):
    for h in range(H):
        if A[h, w] == "#":
            break
        if h == H-1:
            column[w] = True

for r, is_deleted in reversed(list(enumerate(row))):
    if is_deleted:
        A = np.delete(A, r, 0)

for c, is_deleted in reversed(list(enumerate(column))):
    if is_deleted:
        A = np.delete(A, c, 1)

for row in A:
    print("".join(row))
