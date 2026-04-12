r,g,b = map(int,input().split())

x = r*100 + 10*g + b

if x % 4 == 0:
    print('YES')
else:
    print('NO')