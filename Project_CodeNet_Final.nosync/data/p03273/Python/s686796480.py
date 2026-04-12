import numpy as np

h, w = [int(x) for x in input().split()]

a = []
for i in range(h):
    ab = input()
    if '#' in ab:
        a.append(ab)

a2 = []
for i in range(w):
    b = [e[i] for e in a]
    if '#' in b:
        a2.append(b)

a = np.array(a2).T

for row in a:
    print(''.join(row))