x, y, z = map(int,input().split())
a = x / (y + z)
b = x % (y + z)

print(int(a) if b >= z else int(a) - 1)