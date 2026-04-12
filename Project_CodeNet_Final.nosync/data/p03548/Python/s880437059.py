X, Y, Z = map(int, input().split())
for i in range(10**5):
    if X < i * Y + (i + 1) * Z:
        print(i - 1)
        exit()
