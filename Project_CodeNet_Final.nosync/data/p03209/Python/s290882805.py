def thickness(l):
    return 2 ** (l + 2) - 3


def pate(l):
    return 2 ** (l + 1) - 1


def rec(l, x):
    if l == 0:
        return x
    t = thickness(l-1)
    if x <= 1:
        return 0
    elif x <= t + 1:
        return rec(l-1, x-1)
    elif x <= t + 2:
        return pate(l-1) + 1
    elif x <= 2 * t + 2:
        return pate(l-1) + 1 + rec(l-1, x-t-2)
    else:
        return pate(l)


def main():
    n, x = map(int, input().split())
    print(rec(n, x))


main()
