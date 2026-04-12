import numpy as np

N = int(input())
H = np.empty(N)
H = np.array(list(map(int, input().split())))

A = 1
for i in range(1,N):
    if H[i] >=  H[:i].max():
        A += 1
print(A)
