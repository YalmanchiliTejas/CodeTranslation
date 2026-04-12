r, g, b = input().split()
i = r + g + b
if int(i) % 4 == 0:
    print('YES')
else:
    print('NO')