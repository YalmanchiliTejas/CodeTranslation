N, X = map(int, input().split())


def func(n, x):
    if n == 0:
        return 1

    a = pow(2, n + 1) - 3
    b = pow(2, n) - 1

    if x == 1:
        return 0
    elif x <= 1 + a:
        return func(n - 1, x - 1)
    elif x == 2 + a:
        return 1 + b
    elif x <= 2 * a + 2:
        return b + 1 + func(n - 1, x - 2 - a)
    else:
        return 2 * b + 1


print(func(N, X))
