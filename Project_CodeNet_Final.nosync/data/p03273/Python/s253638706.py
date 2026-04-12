# coding: utf-8
H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
B = [[A[i][j] for i in range(H)] for j in range(W)]
check_H = sorted([i for i in range(H) if '#' not in A[i]], reverse=True)
check_W = sorted([i for i in range(W) if '#' not in B[i]], reverse=True)
for i in check_H:
    A = A[:i] + A[i + 1:]
for i in check_W:
    for j in range(len(A)):
        A[j] = A[j][:i] + A[j][i + 1:]
for a in A:
    print(''.join(a))