#!/usr/bin/env python3

N = int(input())

H = list(map(int, input().split()))

num = 1
if N > 2:
    for i in range(1,N):
        cansee = True
        for j in range(i):
            if H[i] < H[j]:
                cansee = False
                break
        if cansee:
            num += 1

print(num)

