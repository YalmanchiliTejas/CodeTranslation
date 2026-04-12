N, X = map(int, input().split())


def length(n):
    return 4*2**n - 3


def func(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    half = length(n) // 2
    if x <= half:
        return func(n - 1, x - 1)
    elif x == half + 1:
        return func(n - 1, x - 1) + 1
    else:
        return (2*2**(n-1) - 1) + 1 + func(n - 1, x - length(n-1) - 2)


print(func(N, X))
