x, y, z = map(int, input().split())
r, q = divmod(x, y + z)
if q >= z:
    print(r)
else:
    print(r - 1)