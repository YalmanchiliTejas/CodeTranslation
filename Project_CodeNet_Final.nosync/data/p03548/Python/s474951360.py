X,Y,Z=map(int,input().split())

s = X//(Y+Z)
if X - s*(Y+Z) < Z:
    print(s - 1)
else:
    print(s)
