r, g, b = map(int, input().split())
n = 100 * r + 10 * g + b
if n % 4 == 0:
    print('YES')
else:
    print('NO')
