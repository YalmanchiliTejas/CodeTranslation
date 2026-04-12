import numpy as np
words = lambda t : list(map(t, input().split()))

n = int(input())
h = words(int)

total = 0
for i in range(n):
    v = True
    for j in range(0,i):
        if h[i] < h[j]:
            v = False
            break
    if v:
        total += 1
print(total )
