# -*- coding: utf-8 -*-

X, Y, Z = map(int, input().split())

used_space = Y + (Z * 2)
ans = 0

while True:
    if used_space > X:
        break
    used_space = used_space + Y + Z
    ans += 1

print(ans)