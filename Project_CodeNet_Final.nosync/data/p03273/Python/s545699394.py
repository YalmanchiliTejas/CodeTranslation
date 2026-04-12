import numpy as np
h, w = map(int, input().split())
f = np.array([list(input()) for _ in range(h)])

f = f[~np.all(f=='.', axis=1), :]
f = f[:, ~np.all(f=='.', axis=0)]

print('\n'.join(''.join(row) for row in f))