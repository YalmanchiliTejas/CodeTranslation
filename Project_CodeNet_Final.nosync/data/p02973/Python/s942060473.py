from bisect import *

N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

r = [10**10] * N
index = -1
for i in range(N):
    j = bisect_right(r, -A[i])
    r[j] = -A[i]
    if j > index:
        index = j
print(index + 1)
