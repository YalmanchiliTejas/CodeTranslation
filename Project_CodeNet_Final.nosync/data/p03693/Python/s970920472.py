a, b, c = map(str, input().split())

if int(a+b+c)%4 == 0:
    print('YES')
else:
    print('NO')
