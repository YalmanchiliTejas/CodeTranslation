r,g,b = map(int, input().split())

total = 100*r + 10*g + b

if total % 4 == 0:
    print('YES')
else:
    print('NO')