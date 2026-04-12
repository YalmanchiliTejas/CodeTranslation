def isu(x, y, z):
    n = int(x / (y + z))
    if x - n * (y + z) - z < 0:
        return int(n - 1)
    return int(n)

x, y, z = map(int, input().strip().split())
print(isu(x, y, z))
