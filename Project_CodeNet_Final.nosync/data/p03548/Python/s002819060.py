x, y, z = map(int, input().split())

x = x - 2 * z
count = 0
while x >= y:
    x = x - y - z
    count += 1

print(count)