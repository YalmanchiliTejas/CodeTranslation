a=list(map(int,input().split()))
if (100*a[0]+10*a[1]+a[2])%4==0:
    print('YES')
else:
    print('NO')