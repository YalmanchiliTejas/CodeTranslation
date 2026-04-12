#!/usr/bin/env python3
X, Y, Z = map(int, input().split())

ans = 0
X -= Z
while X >= Y + Z:
    X -= Y + Z
    ans += 1

print(ans)
