X,Y,Z=map(int,input().split(' '))
if (X-2*Z)%(Y+Z) >= Y:
    print((X-2*Z)//(Y+Z)+1)
else:
    print((X-2*Z)//(Y+Z))