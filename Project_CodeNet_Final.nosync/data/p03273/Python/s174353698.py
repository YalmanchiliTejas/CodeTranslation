a,b = [int(i) for i in input().split()]

import numpy as np
n = []

for i in range(a):
    buf = list(input())
    if "#" in buf:
        n.append(buf)

buffer = []
for i in range(len(n)):
    for j in range(b):
        if "#" in n[i][j]:
            buffer.append(j)

buffer = list(set(buffer))

for i in range(len(n)):
    joined = [n[i][j] for j in buffer]
    print("".join(joined))
