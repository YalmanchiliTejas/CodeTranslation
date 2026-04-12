r,g,b = map(int, input().split())

decimal = r*100 + g*10 + b

if decimal % 4 == 0:
    print('YES')
else:
    print('NO')