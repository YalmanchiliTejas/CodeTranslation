r,g,b=map(lambda x: int(x),input().split())
if (10*g+b)%4==0:
    print('YES')
else:
    print('NO')