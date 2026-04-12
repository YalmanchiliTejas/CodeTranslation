import numpy as np
H, W = map(int, input().split())
A = []
for _ in range(H):
    row = input()
    if row != "." * W:
        A.append(list(row))
A = np.array(A, dtype=str)
B = []
for c in range(W):
    if any(map(lambda c: c == "#", A[:, c])):
        B.append(A[:, c])
for row in np.asarray(B).T:
    print("".join(row))