#!/usr/bin/env python
N = int(input())
c = 1
H = list(map(int, input().split()))
for i in range(1,N):
    for j in range(i):
        if H[i] < H[j]:
            break
    else:
        c += 1
print(c)