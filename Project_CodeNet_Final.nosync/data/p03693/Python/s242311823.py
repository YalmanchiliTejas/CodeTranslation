r, g, b = map(str, input().split())
o = int(r + g + b)
if o%4 == 0:
    print('YES')
else:
    print('NO')