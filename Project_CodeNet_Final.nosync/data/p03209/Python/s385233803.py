N, X = [int(_) for _ in input().split()]


def count(n, x):
    if [n, x] == [0, 1]:
        return 1
    elif x == 1:
        return 0
    elif x < 2 * 2 ** n - 1:
        return count(n - 1, x - 1)
    elif x == 2 * 2 ** n - 1:
        return count(n - 1, 2 * 2 ** n - 3) + 1
    elif x < 4 * 2 ** n - 3:
        return count(n - 1, 2 * 2 ** n - 3) + 1 + \
            count(n - 1, x - 2 * 2 ** n + 1)
    else:
        return 2 * count(n - 1, 2 * 2 ** n - 3) + 1


print(count(N, X))
