# -*- coding: utf-8 -*-
N = int(input())
A = input().split()

B = [0]
for i in range(N):
    B.append(B[i] + int(A[i]))

sum = 0
for i in range(N):
    sum += int(A[i]) * (B[N] - B[i+1])

print(sum % (10**9 + 7))
