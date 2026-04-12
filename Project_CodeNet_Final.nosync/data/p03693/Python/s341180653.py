r, g, b = [int(x) for x in input().split()]

x = 100 * r + 10 * g + b

if x % 4 == 0:
    print('YES')
else:
    print('NO')