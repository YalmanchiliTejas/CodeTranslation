from math import floor

X, Y, Z = map(int, input().split())

if X % (Y + Z) >= Z:
    print(floor( X / (Y + Z)))
else:
    print(floor( X / (Y + Z) - 1))
    