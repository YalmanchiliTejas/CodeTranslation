# coding: utf-8

import sys
input = sys.stdin.readline

N = int(input())
H = list(map(int, input().split()))
# A, B = map(int, input().split())

ans = 0

for i, h in enumerate(H):
    flag = True

    for x in range(i):
        if h < H[x]:
            flag = False
        
    if flag:
        ans += 1

print(ans)

