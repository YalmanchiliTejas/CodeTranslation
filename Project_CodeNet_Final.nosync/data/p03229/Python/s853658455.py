from collections import deque
N = input()
A = [int(input()) for i in range(N)]
coef = [2] * N
coef[0] = 1
coef[-1] = 1
coef1 = [coef[i] if i % 2 == 0 else coef[i] * -1 for i in range(N)]
coef2 = [coef[i] if i % 2 != 0 else coef[i] * -1 for i in range(N)]

A = sorted(A)
coef1 = sorted(coef1)
coef2 = sorted(coef2)
res1 = 0
for i in range(N):
	res1 += A[i] * coef1[i]
res2 = 0
for i in range(N):
	res2 += A[i] * coef2[i]
print max(res1, res2)
