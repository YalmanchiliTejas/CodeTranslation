import numpy as np

H, W = list(map(int, input().split()))
arr = np.array([list(input()) for i in range(H)])
arr = arr[(np.apply_along_axis(lambda line: '#' in line, 1, arr))]
arr = arr[:, (np.apply_along_axis(lambda line: '#' in line, 0, arr))]
for l in arr.tolist():
    print(''.join(l))
