x, y, z = map(int, input().split())

if x < y + 2*z:
    print(0)
else:
    print(1 + (x - (y + 2*z)) // (y + z))
