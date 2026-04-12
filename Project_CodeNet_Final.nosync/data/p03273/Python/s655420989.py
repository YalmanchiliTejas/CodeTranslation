h,w = map(int, input().split())

import numpy as np

f = []
for i in range(h):
    f.append(list(map(lambda x: 0 if x=='.' else 1, list(input()))))
f = np.matrix(f)

for _ in range(2):
    f = f.T
    g = []
    for i in range(f.shape[0]):
        if np.sum(f[i]) > 0:
            g.append(f[i].tolist()[0])
    f = np.matrix(g)

for i in range(len(f)):
    print("".join(list(map(lambda x:str(x), np.array(f[i]).ravel().tolist()))).replace('1','#').replace('0','.'))