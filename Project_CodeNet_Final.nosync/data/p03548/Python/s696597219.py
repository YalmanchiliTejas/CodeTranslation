X, Y, Z = map(int, input().split())

if X < (2*Z + Y):
    print(0)
else:
    print(int((X-Z)/(Z+Y)))
