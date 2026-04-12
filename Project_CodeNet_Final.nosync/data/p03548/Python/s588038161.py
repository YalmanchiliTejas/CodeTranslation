#!/usr/bin/env python3

X, Y, Z = map(int, input().split())

ans = (X-Z) // (Y+Z)

print(ans)