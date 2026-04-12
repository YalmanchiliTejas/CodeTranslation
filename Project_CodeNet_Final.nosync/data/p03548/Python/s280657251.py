X, Y, Z = map(int, input().rstrip().split())
space = Y+Z
X -= Z
print(X//space)
