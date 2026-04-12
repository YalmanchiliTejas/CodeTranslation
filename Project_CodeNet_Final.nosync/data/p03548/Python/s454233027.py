x, y, z = map(int, input().split())
x -= 2 * z
x -= y
if x < 0:
    print(0)
else:
    print(1 + x // (y + z))