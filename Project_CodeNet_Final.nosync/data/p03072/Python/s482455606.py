import numpy as np
N = int(input())
H = np.array(list(map(int, input().split())))
tmp = []
for i in range(1, len(H)):
    tmp.append(all(H[:i]<=H[i]))
print(sum(tmp)+1)