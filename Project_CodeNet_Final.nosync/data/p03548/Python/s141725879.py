x, y, z = map(int, input().split())
total = x // (y + z)
if (x - (total * (y + z) + z)) >= 0:
    pass
else:
    total = max(0, total - 1)
print(total)

