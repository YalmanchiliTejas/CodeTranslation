def f(r, g, b):
    if (100 * r + 10 * g + b) % 4 == 0:
        return 'YES'
    else:
        return 'NO'

r, g, b = map(int, input().split())
print(f(r, g, b))