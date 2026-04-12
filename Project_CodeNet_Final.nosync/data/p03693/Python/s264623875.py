r, g, b = list(map(int, input().split()))

val = g * 10 + b

if val % 4:
    print('NO')
else:
    print('YES')
