def kengo(n, x):
    if n == 0:
        if x == 0:
            return 0
        else:
            return 1
    if x == 0:
        return 0
    if x <= 2 ** (n + 1) - 2:
        return kengo(n - 1, x - 1)
    if x <= 2 ** (n + 2) - 4:
        return 2 ** n + kengo(n - 1, x - 2 ** (n + 1) + 1)
    else:
        return 2 ** (n + 1) - 1

n, x = map(int, input().split())
print(kengo(n, x))
