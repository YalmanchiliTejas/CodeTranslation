import numpy as np

H, W = map(int, input().split())

A = np.zeros((H, W), dtype=np.int)

for i in range(H):
    s = input()
    c = [j for j in range(W) if s[j] == "#"]
    A[i][c] = 1

while True:
    # find x
    a = A.sum(axis=0)
    if np.any(a == 0):
        del_lines = np.where(a == 0)[0]
        A = np.delete(A, del_lines, axis=1)
        continue

    # find y
    a = A.sum(axis=1)
    if np.any(a == 0):
        del_lines = np.where(a == 0)[0]
        A = np.delete(A, del_lines, axis=0)
        continue

    # break if no white line
    break

A = A.tolist()
num2char = {0: ".", 1: "#"}
for l in A:
    s = list(map(lambda x: num2char[x], l))
    print("".join(s))