X,Y,Z=map(int, input().split())

MAX=int(X/(Y+Z))

if MAX*(Y+Z)+Z > X:
    print(MAX-1)
else:
    print(MAX)