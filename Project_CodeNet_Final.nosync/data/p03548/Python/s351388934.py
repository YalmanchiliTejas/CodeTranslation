x, y, z = map(int, input().split())
a = x % (y + z)
b = x // (y + z)
if (a >= z):
    print(b)
else:
    print(b - 1)