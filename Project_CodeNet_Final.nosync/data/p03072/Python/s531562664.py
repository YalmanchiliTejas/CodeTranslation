# Great Ocean View
import numpy as np

# input
N = int(input())
H = np.array(list(map(int, input().split())))

# solve
res = 1
for i in range(1, len(H)):
    if sum(H[:i] - H[i] > 0) == 0:
        res += 1

# output
print(res)