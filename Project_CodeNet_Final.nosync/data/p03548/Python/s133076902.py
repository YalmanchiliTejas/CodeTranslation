from math import floor
X, Y, Z = map(int, input().split())
print(floor((X - Z)/(Y + Z)))