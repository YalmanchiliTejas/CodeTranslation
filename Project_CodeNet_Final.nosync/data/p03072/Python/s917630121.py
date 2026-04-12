import numpy as np

N = int(input())
l = input().split()
l = np.array(l)
l = l.astype(int)
count = 1
for i in range(1, len(l)):
    if np.max(l[:i]) <= l[i]:
        count += 1
print(count)