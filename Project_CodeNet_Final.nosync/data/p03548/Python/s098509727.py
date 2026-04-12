import math
X, Y, Z = tuple(map(int, input().split()))
print(math.floor((X-Z)/(Y+Z)))