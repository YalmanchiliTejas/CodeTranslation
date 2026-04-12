r, g, b = map(int, input().strip().split())
color = r * 100 + g * 10 + b
if color % 4 == 0:
    print('YES')
else:
    print('NO')
