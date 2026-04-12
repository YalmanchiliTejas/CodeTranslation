x, y, z = map(int, input().split())
c = 0
while True:
    x -= z + y
    if x >= z:
        c += 1
    else:
        break
print(c)
