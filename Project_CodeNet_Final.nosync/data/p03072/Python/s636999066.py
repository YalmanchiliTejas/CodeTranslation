import numpy as np
N = int(input())
input_H = input().split()
H = np.empty(N, int)
for i in range(N):
    H[i] = int(input_H[i])

max = H[0]
num = 1
for i in range(1, N):
    if H[i] >= max:
        num += 1
        max = H[i]
print(int(num))