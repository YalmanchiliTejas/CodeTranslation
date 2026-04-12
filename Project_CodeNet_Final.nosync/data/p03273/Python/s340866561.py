import numpy as np
h, w = map(int, input().split())
field = []
for _ in range(h):
    row = list(input())
    field.append(row)
field = np.array(field)


deleterow = []
deleteline = []
for i in range(field.shape[0]):
    if set(field[i,:])=={'.'}:
        deleterow.append(i)
for j in range(field.shape[1]):
    if set(field[:,j])=={'.'}:
        deleteline.append(j)

for i, row in enumerate(field):
    if i in deleterow:
        continue
    for j, val in enumerate(row):
        if j in deleteline:
            continue
        print(val, end='')
    print('')