import numpy as np
h, w = list(map(int, input().split()))
a = np.array([list(input()) for i in range(h)])
a = a[:, ~np.all(a=='.', axis=0)]
a = a[~np.all(a=='.', axis=1)]
for i in range(len(a)):
    print(''.join(a[i]))