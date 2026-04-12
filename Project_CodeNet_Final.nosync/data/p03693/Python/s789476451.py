r, g, b = [int(_) for _ in input().split()]

if ( g * 10 + b) % 4 == 0:
    print('YES')

else:
    print('NO')
