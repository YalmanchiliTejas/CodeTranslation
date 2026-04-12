X, Y, Z = map(int, input().split())
i = 1
while True:
    if (i + 1) * Z + i * Y > X:
        print(i - 1)
        break
    i += 1