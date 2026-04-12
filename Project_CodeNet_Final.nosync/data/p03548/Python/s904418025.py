x, y, z = map(int, input().split())
a = x // (y + z)
b = x % (y + z)
if b >= z:
    print(a)
else:
    print(a - 1)