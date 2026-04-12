x, y, z = map(int, input().split())
c = x // (y + z)
d = x % (y + z)
if d >= z:
    print(c)
else:
    print(c - 1)