import sys

r,g,b = input().split()

if 1 > int(r) or 1 > int(g) or 1 > int(b) or 9 < int(r) or 9 < int(g) or 9 < int(b):
    sys.exit()

if int(r + g + b)%4 == 0:
    print('YES')
else:
    print('NO')

