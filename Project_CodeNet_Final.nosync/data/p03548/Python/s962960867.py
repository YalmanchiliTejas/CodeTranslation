x, y, z = map(int, input().split())
i = 0
while x - (y + z) * i > 0:
    i += 1

t = x - (y + z) * (i - 1)
if t >= z:
    print(i - 1)
else:
    print(i - 2)