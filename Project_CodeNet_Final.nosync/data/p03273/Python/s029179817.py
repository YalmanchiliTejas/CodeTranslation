import numpy as np

H, W = map(int, input().split())
a = [list(input()) for i in range(H)]
arr = np.array(a)

for i in reversed(range(arr.shape[0])):
    if not '#' in arr[i]:
        arr = np.delete(arr, i, 0)
        
for i in reversed(range(arr.shape[1])):
    if not '#' in arr[:,i]:
        arr = np.delete(arr, i, 1)

a = arr.tolist()

for i in range(len(a)):
    print(''.join(a[i]))