a,b,c=map(int,input().split())
n=a*100+b*10+c*1
if n%4==0:
    print('YES')
else:
    print('NO')