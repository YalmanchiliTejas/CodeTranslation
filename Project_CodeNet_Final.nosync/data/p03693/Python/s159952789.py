r,g,b = map(str,input().split())
value = r+g+b

if int(value)%4 == 0:
    print('YES')
else:
    print('NO')