def abc107_b():
    import numpy as np

    h, w = map(int, input().split())
    a = []
    for i in range(h):
        tmp = list(input())
        if not tmp == ["."] * w:
            a = np.append(a, tmp)
    a = a.reshape((-1, w))

    return a[:, np.any(a != np.array(["."] * w), axis=0)]

for row in abc107_b():
    print("".join(row))