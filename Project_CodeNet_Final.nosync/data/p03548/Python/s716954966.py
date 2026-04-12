x, y, z = map(int, input().split())
humans = 1
if x >= (y + 2 * z):
    x -= (z + y + z)
    while x >= (y + z):
        x -= (y + z)
        humans += 1
    print(humans)
else:
    print(0)
