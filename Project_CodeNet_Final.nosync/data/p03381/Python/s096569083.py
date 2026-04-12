import numpy as np

N = int(input())
X = list(map(int, input().split()))

sort_X = sorted(X)
l = sort_X[int(N/2 - 1)]
r = sort_X[int(N/2)]

for i in range(N):
    if (X[i] <= l):
        print(r)
    else:
        print(l)
