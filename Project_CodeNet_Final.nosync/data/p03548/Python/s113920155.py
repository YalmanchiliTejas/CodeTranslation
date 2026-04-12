x, y, z = map(int, input().split())

count = 0
if x >= y + 2 * z:
    count += 1
    x -= y + 2 * z

count += x // (y + z)
print(count)