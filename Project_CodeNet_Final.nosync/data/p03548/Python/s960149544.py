def resolve():
    x, y, z = map(int, input().split())

    x -= z
    count = 0
    while True:
        x = x-(y+z)
        if x >= 0:
            count += 1
        else:
            break
    print(count)
resolve()