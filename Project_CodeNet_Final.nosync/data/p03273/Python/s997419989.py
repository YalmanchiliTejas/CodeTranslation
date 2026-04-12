import numpy as np

H, W = map(int, input().split())

A = np.empty((H, W), dtype='str')
for i in range(H):
    A[i, :] = list(input())


def delete_row(A):
    nrow = A.shape[0]
    ncol = A.shape[1]

    idx = []
    for i in range(nrow):
        if (''.join(A[i, :]) != '.'*ncol):
            idx.append(i)
    return(A[idx, :])


def delete_col(A):
    nrow = A.shape[0]
    ncol = A.shape[1]

    idx = []
    for i in range(ncol):
        if (''.join(A[:, i]) != '.'*nrow):
            idx.append(i)
    return(A[:, idx])

while(True):
    nrow, ncol = A.shape
    A = delete_row(A)
    A = delete_col(A)
    nrow_, ncol_ = A.shape
    if (nrow_ == nrow and ncol_ == ncol):
        break

for i in range(A.shape[0]):
    print(''.join(A[i, :]))
