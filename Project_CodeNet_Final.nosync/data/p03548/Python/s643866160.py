X,Y,Z=map(int,input().split())
print(X//(Y+Z) if (X%(Y+Z))>=Z else (X//(Y+Z))-1)