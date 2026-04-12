num = input().split()
str_multiple = num[1]+num[2]
multiple = int(str_multiple)
if multiple%4 == 0:
    print('YES')
else:
    print('NO')
