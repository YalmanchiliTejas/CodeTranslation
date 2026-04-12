import numpy as np
h, w = map(int, input().split())
a = np.array([list(input()) for i in range(h)])

new_a= np.empty((0,len(a[0])), dtype='<U1')
for i in a:
    if "#" in i:
        new_a = np.append(new_a, [i], axis=0)
a = new_a.T
new_a= np.empty((0,len(a[0])), dtype='<U1')
for i in a:
    if "#" in i:
        new_a = np.append(new_a, [i], axis=0)
a = new_a.T
for i in a:
    print("".join(i))