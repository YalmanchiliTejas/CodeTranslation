x, y, z = map(int, input().split())
x -= z * 2
c = x // (y + z)
if x - (y + z) * c >= y:
    c += 1
print(c)
