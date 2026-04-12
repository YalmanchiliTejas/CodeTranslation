r,g,b=map(int,input().split())
l=str(r)+str(g)+str(b)
if int(l)%4==0:
    print('YES')
else:
    print('NO')