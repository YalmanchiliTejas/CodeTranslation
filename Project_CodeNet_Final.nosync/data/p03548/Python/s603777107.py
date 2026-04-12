import math
X, Y, Z = map(int, input().split())

X -= Z

print(math.floor(X/(Y+Z)))
