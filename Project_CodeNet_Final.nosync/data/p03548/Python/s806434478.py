x, y, z = map(int, input().split())

rm = x % (y+z)
a = -1 if rm < z else 0
print(x // (y + z) + a)