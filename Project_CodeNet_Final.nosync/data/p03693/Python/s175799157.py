r,g,b = list(map(int,input().split()))
rgb = int(str(r)+str(g)+str(b))%4
if rgb:
    print('NO')
else:
    print('YES')