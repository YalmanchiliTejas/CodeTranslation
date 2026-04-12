a=map(int,input().split())
b=[c for c in a]
if (b[1]*10+b[2])%4==0:
    print('YES')
else:
    print('NO')
    