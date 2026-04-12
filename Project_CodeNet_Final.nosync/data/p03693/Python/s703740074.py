
[r,g,b] = list(map(int,input().split()))
dam=100*r + 10*g + 1*b

if dam%4==0:
    print('YES')
else:
    print('NO')
