r, g, b = map(int, input().split())
d = 10*g + b
if d%4 == 0:
    print('YES')
else:
    print('NO')
