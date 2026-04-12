r,g,b=map(int,input().split())
ans=r*100+g*10+b
if ans%4==0:
    print('YES')
else:
    print('NO')