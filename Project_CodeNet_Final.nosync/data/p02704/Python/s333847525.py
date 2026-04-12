import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
import numpy as np

N = int(readline())
S = np.array(readline().split(), np.uint64)
T = np.array(readline().split(), np.uint64)
U = np.array(readline().split(), np.uint64)
V = np.array(readline().split(), np.uint64)


def solve(S, T, U, V):
    A = np.zeros((N, N), np.uint64)
    if N == 1:
        return np.array([[U[0]]], np.uint64)
    all_one_row = (S == 0) & (U == 1)
    all_zero_row = (S == 1) & (U == 0)
    r = np.any(all_zero_row), np.any(all_one_row)
    all_one_col = (T == 0) & (V == 1)
    all_zero_col = (T == 1) & (V == 0)
    c = np.any(all_zero_col), np.any(all_one_col)
    if (c[0] or c[1]) and not (r[0] or r[1]):
        return solve(T, S, V, U).T
    # 確定条件があるなら行にある
    if not (r[0] or r[1]):
        # 確定条件なし。十分均一ならok
        A[1::2, ::2] = 1
        A[::2, 1::2] = 1
        return A
    # 少なくとも行に確定条件がある場合
    if r[0] and r[1]:
        # 列の運命は確定なので、行本位で入れればよい
        A += U[:, None]
        return A
    if r[0]:
        if c[1]:
            return A
        if c[0]:
            # 行列とも強制的に 0 が入る。他は 1 を埋める。
            A += 1
            A[all_zero_row, :] = 0
            A[:, all_zero_col] = 0
            return A
        # 列に強制条件なし
        if np.any(U == 1):
            A += U[:, None]
            return A
        # 行は、all or exists で 0
        # 列は、exists 0 or 1
        if np.any(V == 0):
            A += V[None, :]
            A[all_zero_row] = 0
            return A
        if N - 1 <= np.count_nonzero(all_zero_row):
            return A
        ind = np.where(~all_zero_row)[0]
        A[ind[0], 0] = 1
        A[ind[-1], 1:] = 1
        return A
    if r[1]:
        if c[0]:
            return A
        if c[1]:
            # 行列とも強制的に 1 が入る。他は 0 を埋める。
            A[all_one_row, :] = 1
            A[:, all_one_col] = 1
            return A
        # 列に強制条件なし
        if np.any(U == 0):
            A += U[:, None]
            return A
        # 行は、all or exists で 1
        # 列は、exists 0 or 1
        if np.any(V == 1):
            A += V[None, :]
            A[all_one_row] = 1
            return A
        if N - 1 <= np.count_nonzero(all_one_row):
            return A
        A += 1
        ind = np.where(~all_one_row)[0]
        A[ind[0], 0] = 0
        A[ind[-1], 1:] = 0
        return A


def test(S, T, U, V, A):
    row_or = np.bitwise_or.reduce(A, axis=1)
    row_and = np.bitwise_and.reduce(A, axis=1)
    cond_row = np.all(U[S == 0] == row_and[S == 0]) and np.all(U[S == 1] == row_or[S == 1])
    col_or = np.bitwise_or.reduce(A, axis=0)
    col_and = np.bitwise_and.reduce(A, axis=0)
    cond_col = np.all(V[T == 0] == col_and[T == 0]) and np.all(V[T == 1] == col_or[T == 1])
    return cond_row and cond_col


A = np.zeros((N, N), np.uint64)
for k in range(64):
    A ^= solve(S, T, (U >> k) & 1, (V >> k) & 1) << k

if not test(S, T, U, V, A):
    print(-1)
else:
    print('\n'.join(' '.join(row) for row in A.astype(str)))
