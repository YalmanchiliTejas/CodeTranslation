import numpy as np

def ABC107B(h, w, a):
    b = np.zeros((h, w), dtype=str)
    for i in range(h):
        b[i, :] = np.array(list(a[i]))
    H = []
    W = []
    for i in range(h):
        if any(b[i, :] == '#'):
            H.append(i)
    for j in range(w):
        if any(b[:, j] == '#'):
            W.append(j)
    lenH = len(H)
    lenW = len(W)
    for i in range(h):
        if H.count(i) == 1:
            string = ''
            for j in range(w):
                if W.count(j) == 1:
                    string = string + b[i, j]
            print(string)

h, w = map(int, input().split())
a = [0] * h
for i in range(h):
    a[i] = input()
ABC107B(h, w, a)
