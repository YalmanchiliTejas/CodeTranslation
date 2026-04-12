import numpy as np
H, W = map(int, input().split())
a = np.array([list(input()) for _ in range(H)])

# 行
del_index_0 = []
for i in range(H):
    if np.all(a[i]==['.']*W):
        del_index_0.append(i)
b = np.delete(a, del_index_0, axis=0)

# 列
del_index_1 = []
for i in range(W):
    if np.all(b[:,i]==['.']*(H-len(del_index_0))):
        del_index_1.append(i)
c = np.delete(b, del_index_1, axis=1)

for i in c:
    print(''.join(i))