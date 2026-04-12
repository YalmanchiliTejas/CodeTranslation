import numpy as np
H, W = map(int, input().split())
a = []
for i in range(H):
    a_l = input()
    a.append([c for c in a_l])


for i in range(H):
    for j in range(W):
        if a[i][j] == '.':
            a[i][j] = 1
        elif a[i][j] == '#':
            a[i][j] = 0
        else:
            pass
a = np.array(a)
v = []
h = []
for i in range(H):
    if np.sum(a[i,:]) == W:
        h.append(i)
for j in range(W):
    if np.sum(a[:,j]) == H:
        v.append(j)

a_del = np.delete(np.delete(a, v, 1), h, 0)
a_del = list(a_del)

for i in range(len(a_del)):
    for j in range(len(a_del[i])):
        if a_del[i][j] == 1:
            print('.', end='')
        elif a_del[i][j] == 0:
            print('#', end='')
    print('')