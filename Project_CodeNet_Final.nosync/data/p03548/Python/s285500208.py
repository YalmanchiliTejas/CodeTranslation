X,Y,Z=map(int,input().split())
a=X//(Y+Z)
if X>=a*(Y+Z)+Z:
    print(a)
else:
    print(a-1)
    