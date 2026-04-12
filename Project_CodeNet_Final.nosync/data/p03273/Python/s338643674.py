 #ABC107, B - grid comprehension
import numpy as np
h, w = map(int, input().split(' '))
A = np.array([list(input()) for i in range(h)])


row_change = 1
col_change = 1
while(row_change == 1 or col_change == 1):
    row_change = 0
    col_change = 0
    row_del = []
    col_del = []

    for i in range(A.shape[0]):
        if all([a == '.' for a in A[i,:]]):
            row_del.append(i)
            row_change = 1
    A = np.delete(A, row_del, 0)

    for j in range(A.shape[1]):
        if all([a == '.' for a in A[:,j]]):
            col_del.append(j)
            col_change = 1
    A = np.delete(A, col_del, 1)

for i in range(A.shape[0]):
    print(''.join(A[i,:]))
