#!/usr/bin/env python3

N = int(input())
H = []
h = input().split()

for i in range(N):
    h_n = int(h[i])
    H.append(h_n)

ans = 1
for j in range(1,N):
    if all([H[j] >= H[k] for k in range(0,j)]):
        ans += 1

print(ans)
    
