r, g, b = map(int, input().split())
total = g*10 + b
if total % 4 == 0:
    print('YES')
else:
    print('NO')