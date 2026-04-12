import numpy as np

n = int(input())
h = np.array([int(x) for x in input().split()])

count = 0
max = h[0]
for i in range(n):
    if h[i] >= max:
        count += 1
        max = h[i]

print(count)