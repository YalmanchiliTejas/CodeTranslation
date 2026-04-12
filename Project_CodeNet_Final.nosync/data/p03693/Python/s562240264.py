a = list(map(int,input().split()))
r=a[0]
g=a[1]
b=a[2]

if (r*100+g*10+b)%4==0:
    print('YES')
else:
    print('NO')
