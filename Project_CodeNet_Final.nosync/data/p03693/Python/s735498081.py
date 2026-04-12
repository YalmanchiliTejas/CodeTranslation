a,b,c = map(int, input().split())

total = a*100+b*10+c

if total%4 == 0:
    print('YES')
else:
    print('NO')