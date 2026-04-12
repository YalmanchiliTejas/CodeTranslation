# -*- coding: utf-8 -*-

# 整数の入力
n = int(input())
# スペース区切りの整数の入力
h = list(map(int, input().split()))

baseHeight = h[0]
canViewCnt = 1

for i in range(1,n):
    canView = True
    for j in range(i):
        if h[i] < h[j]:
            canView = False
            break
    if canView == True:
        canViewCnt += 1

# 出力
print(str(canViewCnt))
