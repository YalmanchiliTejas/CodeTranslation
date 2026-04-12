x, y, z = map(int, input().split())
for i in range(200000):
    if x < y * i + z * (i + 1):
        print(i - 1)
        break