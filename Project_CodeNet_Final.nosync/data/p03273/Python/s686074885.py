import numpy as np
m = []
h, w = map(int, input().split())
for i in range(h):
    arr = list(input())
    if '#' in arr:
        m.append(arr)
    else:
        pass
m = np.array(m).T.tolist()
output = []
for i in range(w):
    if '#' in m[i]:
        output.append(m[i])
    else:
        pass
output = np.array(output).T.tolist()
for i in range(len(output)):
    print(''.join(output[i]))
    