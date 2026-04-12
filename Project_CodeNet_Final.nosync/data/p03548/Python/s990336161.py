x, y, z = map(int, input().split())
ans = 1

q = x // (y + z)
r = x % (y + z)

if r < z:
    print(q - 1)
else:
    print(q)