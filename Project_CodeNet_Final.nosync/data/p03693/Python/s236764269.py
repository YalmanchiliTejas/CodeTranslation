def actual(r, g, b):
    rgb = 100 * r + 10 * g + b

    if rgb % 4 == 0:
        return 'YES'

    return 'NO'

r, g, b = map(int, input().split())
print(actual(r, g, b))