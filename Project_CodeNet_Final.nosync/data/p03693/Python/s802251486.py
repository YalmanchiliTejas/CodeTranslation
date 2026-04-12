r, g, b = map(int, input().split())

num = 100 * r + 10  * g + b

if num % 4:
    print('NO')
else:
    print('YES')
