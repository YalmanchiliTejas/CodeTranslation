import math

X,Y,Z=map(int,input().split())

if X<Z:
    print(0)
else:
    print(math.floor((X-Z)/(Y+Z)))