# -*- coding: utf-8 -*-

r, g, b = map(int, input().split())

value = r * 100 + g * 10 + b

print("YES" if value % 4 == 0 else "NO")