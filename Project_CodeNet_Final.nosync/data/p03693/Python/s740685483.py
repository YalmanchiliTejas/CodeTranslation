r, b, g = map(str, input().split())

if int(r + b + g) % 4 == 0:
    print('YES')
else:
    print('NO')