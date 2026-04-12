r,g,d =(int(x) for x in input().split())

num = 100 * r + g * 10 + d

if num % 4 == 0:
    print('YES')
else:
    print('NO')