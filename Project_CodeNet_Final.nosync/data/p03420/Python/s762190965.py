n, k = map(int, input().split())


def count():
    if k == 0:
        return n * n

    c = 0
    for i in range(k+1, n+1):
        c += (n // i) * (i - k) + max((n % i) - k + 1, 0)

    return c


print(count())