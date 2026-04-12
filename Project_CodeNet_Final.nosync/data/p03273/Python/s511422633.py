import numpy as np

H, W, *M = open(0).read().split()
H = int(H)
W = int(W)
M = np.array([list(r) for r in M])

del_rows = []

M_ans = M

for i in range(H):
    if "#" not in M_ans[i]:
         del_rows.append(i)
            
M_ans = np.delete(M_ans, del_rows, 0)

del_cols = []

for j in range(len(M_ans.T)):
    if "#" not in M_ans.T[j]:
         del_cols.append(j)
            
M_ans = np.delete(M_ans, del_cols, 1)

print(*["".join(r) for r in M_ans], sep="\n")