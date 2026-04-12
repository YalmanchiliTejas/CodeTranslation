# -*- coding: utf-8 -*-


N = int(input())
e = [int(i) for i in input().split()]

ans = 0

for i in range(len(e)):
    if i==0:
        ans += 1
        continue

    flg = True
    for i2 in range(i+1):
        if e[i2]>e[i]:
            flg = False

    if flg:
        ans += 1

print(ans)