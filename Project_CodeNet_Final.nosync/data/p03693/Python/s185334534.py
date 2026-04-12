r,g,b=map(int,input().split())
result=r*100+g*10+b
if result%4==0:
    print('YES')
else:
    print('NO')