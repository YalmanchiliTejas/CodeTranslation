
import numpy as np
N = int(input())
A = np.array([int(i) for i in input().split()])

K = 0
while max(A) >= N:
    p = A // N
    S = sum(p)
    q = S - p
    A = A - p * N + q
    K += sum(p)

print(K)
