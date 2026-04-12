import numpy as np
h, w = map(int, input().split())

field = [list(input()) for x in range(h)]
for i, row in list(enumerate(field))[::-1]:
    if "#" not in row:
        del field[i]

field = list(np.transpose(field))
for i, row in list(enumerate(field))[::-1]:
    if "#" not in row:
        del field[i]

for i in np.transpose(field):
    print("".join(i))