# -*- coding: utf-8 -*-
X,Y,Z = map(int,input().split())

ans = 0
while True:
    if Y * ans + Z * (ans + 1) <= X:
        ans += 1
    else:
        break
print(ans - 1)
