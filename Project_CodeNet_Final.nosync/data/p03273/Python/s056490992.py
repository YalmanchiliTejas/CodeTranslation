import numpy as np
h, w = map(int, input().split())
field = [list(input()) for _ in range(h)]

#%%
np_field = np.array(field)
cols = np.logical_not(np.all(np_field=='.', axis=0))
rows = np.logical_not(np.all(np_field=='.', axis=1))

ans = np_field[np.ix_(rows, cols)]

for a in ans:
    print(''.join(map(str, a)))