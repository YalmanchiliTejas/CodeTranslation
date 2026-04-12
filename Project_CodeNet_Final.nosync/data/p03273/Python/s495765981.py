import numpy as np
h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

a = np.array(a).reshape(h, w)
a = [i for i in a if "#" in i]

a = np.array(a).T
a = [i for i in a if "#" in i]

a = np.array(a).T
for i in a:
    print("".join(i))
