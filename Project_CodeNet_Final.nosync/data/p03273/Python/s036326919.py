import numpy as np

h, w = list(map(int, input().split()))
A = np.array([list(input()) for i in range(h)])

D = A[A == "."]

while True:

    B = A[np.any(A != ".", axis= 1)]
    B = B[:, np.any(A != ".", axis = 0)]

    if np.array_equal(A, B) == True:
        break
    else:
        A = B 

for i in range(len(A)):
    print("".join(A[i]))