r, g, b = map(str, input().split())

figure = int(r+g+b)

if figure%4==0:
    print('YES')
else:
    print('NO')
