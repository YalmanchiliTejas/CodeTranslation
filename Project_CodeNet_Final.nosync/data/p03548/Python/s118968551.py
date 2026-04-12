X, Y, Z = map(int, input().split())
for i in range(100000):
    if X / (i* Y + (i + 1) * Z) >= 1:
        pass
    else:
        print(i - 1)
        break