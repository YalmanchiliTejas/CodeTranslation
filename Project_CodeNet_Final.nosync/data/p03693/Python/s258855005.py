r,g,b = input().split()

if int(''.join([r,g,b]))%4==0:
    print('YES')
else:
    print('NO')