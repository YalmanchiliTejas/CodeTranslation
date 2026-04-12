# -*- coding: utf-8 -*-

r, g, b = map(int, list(input().split()))

num = r * 100 + g * 10 + b

if num % 4:
    print('NO')
else:
    print('YES')
