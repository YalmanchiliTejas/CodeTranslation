def resolve():
    r,g,b=map(int, input().split())
    if eval(str(r)+str(g)+str(b))%4==0:
        print('YES')
    else:
        print('NO')
resolve()
