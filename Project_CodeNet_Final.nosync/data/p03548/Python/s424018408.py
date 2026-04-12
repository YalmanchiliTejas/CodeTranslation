x, y, z = map(int, input().split())
q, m = divmod(x, (y+z))
print(q if m >= z else q-1)
