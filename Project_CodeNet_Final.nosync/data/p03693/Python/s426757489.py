r,g,b = map(str, input().split())
num = r + g + b
if int(num)%4 == 0:
    print('YES')
else:
    print('NO')

