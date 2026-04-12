X,Y,Z = map(int, input().split())

X -= 2*Z + Y

print(X // (Y + Z) + 1)
