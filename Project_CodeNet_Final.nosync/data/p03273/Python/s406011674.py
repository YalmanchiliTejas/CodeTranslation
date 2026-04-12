import numpy as np

h, w = map(int, (input().split()))
raw = np.array([list(input()) for i in range(h)])

v_removed = raw[:, np.any(raw == '#', axis=0)]
vh_removed = v_removed[np.any(v_removed == '#', axis=1), :]

for s in vh_removed.tolist():
    print(''.join(s))
