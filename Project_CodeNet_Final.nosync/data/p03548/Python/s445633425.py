def abc078_b():
    x, y, z = map(int, input().split())
    n = x // (y + z)
    if n * (y + z) + z <= x:
        print(n)
    else:
        print(n - 1)


abc078_b()