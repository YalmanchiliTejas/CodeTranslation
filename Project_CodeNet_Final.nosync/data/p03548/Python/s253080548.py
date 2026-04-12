X, Y, Z = map(int,input().split())
print([X//(Y+Z)-1,X//(Y+Z)][X%(Y+Z)-Z>=0])