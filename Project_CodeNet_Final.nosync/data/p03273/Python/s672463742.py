import numpy as np

H, W = map(int, input().split(" "))

lines = np.asarray([list(input().replace("\n", "")) for h in range(H)])

h_indexs, w_indexs = map(set, np.where(lines == "#"))

outlines = lines[list(h_indexs), :][:, list(w_indexs)]
for outline in outlines:
    print("".join(outline))