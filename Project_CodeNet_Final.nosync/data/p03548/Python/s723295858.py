x, y, z = map(int, input().split())
for i in range(x):
    m = i * (y + z) + z
    if m > x:
        break
print(i - 1)