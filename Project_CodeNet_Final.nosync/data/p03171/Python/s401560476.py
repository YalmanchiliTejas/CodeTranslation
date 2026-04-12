import numpy as np

n = int(input())
a = np.array([int(i) for i in input().split()], dtype=np.int64)

s = np.copy(a)
for i in range(1, n):
    s = np.maximum(a[:n-i]-s[1:n-i+1], a[i:]-s[:n-i])

print(s[0])
