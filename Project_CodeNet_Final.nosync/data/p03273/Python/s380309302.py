h, w = map(int, input().split())
a = []
for _ in  range(h):
    k = input()
    if "#" in k:
        a.append([i for i in k])
        
import numpy as np
for i in np.array([i for i in np.array(a).T if "#" in i]).T.tolist():
    print("".join(i))