# coding: utf-8
N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))
A.sort()
L1, L2 = [0] * N, [0] * N
L1[0] = A[N//2]
L2[0] = A[N//2]
for i in range(1, N):
    if i % 2 == 0:
        L1[i] = A[i//2-1]
        L2[i] = A[-i//2]
    else:
        L1[i] = A[-i//2]
        L2[i] = A[i//2]
a1, a2 = 0, 0
for i in range(N-1):
    a1 += abs(L1[i] - L1[i+1])
    a2 += abs(L2[i] - L2[i+1])
print(max(a1, a2))