import numpy as np

H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

a = [a[idx] for idx in range(len(a)) if a[idx].count(".") < len(a[idx])]
a = np.array(a).T.tolist()
a = [a[idx] for idx in range(len(a)) if a[idx].count(".") < len(a[idx])]
a = np.array(a).T.tolist()

for row in range(len(a)):
    print("".join(a[row]))