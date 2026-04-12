X, Y, Z = map(int, input().split())
if X - Y -2*Z >= 0:
    print(1+(X-Y-2*Z)//(Y+Z))
else:
    print(0)