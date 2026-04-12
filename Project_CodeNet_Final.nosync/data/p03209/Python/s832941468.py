n, x = map(int, input().split())


def pi(n):
    return 2**(n+1)-1


def ai(n):
    return 2**(n+2) - 3


def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    else:
        if x <= 1:
            return 0
        elif (x <= 1 + ai(n-1)):
            return f(n - 1, x - 1)
        elif x == 2 + ai(n - 1):
            return pi(n - 1) + 1
        elif (2 + ai(n - 1) < x) and (x <= 2 + 2 * ai(n - 1)):
            return pi(n-1) + 1 + f(n-1, x-2-ai(n-1))
        elif x >= ai(n):
            return pi(n)


print(f(n, x))
