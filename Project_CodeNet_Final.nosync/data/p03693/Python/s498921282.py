import sys
r, g, b = map(int, sys.stdin.readline().split())

if (r * 100 + g * 10 + b) % 4 == 0:
    print('YES')
else:
    print('NO')