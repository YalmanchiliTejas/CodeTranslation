def pat(n, x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    a = 2 ** (n + 2) - 3
    if a // 2 + 1 <= x:
        return 2 ** n + pat(n - 1, x - a // 2 - 1)
    elif a // 2 == x:
        return 2 ** n - 1
    else:
        return pat(n - 1, x - 1)


n, x = map(int, input().split())
print(pat(n, x))