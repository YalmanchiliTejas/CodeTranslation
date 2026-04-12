(x, y, z) = map(int, input().split())
for i in range(1, 1000000):
    if y * i + z * (i + 1) > x:
        print(i - 1)
        break
    else:
        continue
        