a,b,c=map(int,input().split(' '))
i = (a*100+b*10+c) % 4
if i == 0:
    print('YES')
else:
    print('NO')