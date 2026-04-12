#!/usr/bin/env python3

N = int(input())
X = list(map(int, input().split()))
D = {}
for i in range(N):
    D[i] = X[i]

X = sorted(X)
ans = [X[N//2-1], X[N//2]]
A = {}

cnt = 0
for i, v in sorted(D.items(), key=lambda x:x[1]):
    if cnt < N // 2:
        A[i] = ans[1]
    else:
        A[i] = ans[0]
    cnt += 1

for i, v in sorted(A.items(), key=lambda x:x[0]):
    print(v)
