x, y, z = map(int, input().split())

total = 0
count = 0

while total <= x-z:
    total += z + y
    count += 1

print(count-1)