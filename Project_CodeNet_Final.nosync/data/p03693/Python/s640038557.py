a,b,c=map(int,input().split())
ans = 10*b+c
ans %= 4
if ans == 0:
    print('YES')
else:
    print('NO')