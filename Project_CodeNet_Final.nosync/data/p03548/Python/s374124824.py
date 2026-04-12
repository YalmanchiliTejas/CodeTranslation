x, y, z = map(int, input().split())

count = x // (y + z)

if x < (y + z) * count + z:
    count -= 1

print(count)