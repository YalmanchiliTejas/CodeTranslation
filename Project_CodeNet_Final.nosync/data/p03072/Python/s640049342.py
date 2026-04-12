import numpy as np
N = int(input())
H = list(map(int, input().split()))
max_h = 0
count = 0

for h in H:
    if h >= max_h:
        max_h = h
        count += 1
print(count)

#H_max = np.amax(H)
#H_max_index = np.argmax(H)
