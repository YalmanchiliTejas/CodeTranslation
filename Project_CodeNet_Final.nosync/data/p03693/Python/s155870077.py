a = list(map(int,input().split()))
num = 100*a[0]+ 10*a[1] + a[2]
if num %4 == 0:
    print('YES')
else:
    print('NO')