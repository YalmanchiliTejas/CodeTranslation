# -*- coding: utf-8 -*-

# input
N = int(input())
H = list(map(int, input().split()))

# solve
ans = 1
for i in range(1, N):
    flag = True
    for j in range(i):
        if H[j] > H[i]:
            flag = False
    if flag:
        ans += 1

# output
print(ans)
