x, y, z = map(int, input().split())

x -= 2 * z
print(x // (y + z) + x % (y + z) // y)