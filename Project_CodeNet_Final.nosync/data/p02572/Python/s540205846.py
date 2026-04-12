import numpy as np

N = int(input())
A = list(map(int, input().split(' ')))

modn = int(1e9 + 7)

ruiseki = sum(A)

ret = 0
for i in range(0, len(A)-1):
  ruiseki -= A[i]
  ret += A[i] * ruiseki

print(np.mod(ret, modn))