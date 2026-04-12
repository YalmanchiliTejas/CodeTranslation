
x, a, b= list(map(int, input().split()))

if ((x*100+a*10+b)%100)%4==0:
    print('YES')
else:
    print('NO')