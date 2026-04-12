r, g, b = map(int, input().split())
number = int(str(r) + str(g) + str(b))

if number % 4 == 0:
    print('YES')
else:
    print('NO')