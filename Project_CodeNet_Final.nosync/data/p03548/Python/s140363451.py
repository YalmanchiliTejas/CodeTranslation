x, y, z = map(int, input().split())

if x - y - 2 * z < 0:
    print(0)

print(1 + (x - y - 2 * z) // (y + z))
