def resolve():
    a,b,c=map(int,input().split())
    print('YES' if int(str(a)+str(b)+str(c))%4==0 else 'NO' )
resolve()