#!/usr/bin/env python3

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
B = []

for i in range(len(A)):
    if ''.join(A[i]) != '.'*len(A[i]):
        B.append(A[i])


C = list(zip(*B))
R = []
for i in range(len(C)):
    if ''.join(C[i]) != '.'*len(C[i]):
        R.append(C[i])

R = list(zip(*R))

for r in R:
    print(''.join(r))
