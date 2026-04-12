N = input()
K = int(input())


def f(n, d, k):
    if k == 0:
        return 1
    if d == 1:
        return int(n) if k == 1 else 0
    msb = int(n[0])
    if msb == 0:
        return f(n[1:], d - 1, k)
    return f(n[1:], d - 1, k - 1) + (msb - 1) * f('9' * (d - 1), d - 1, k - 1) + f('9' * (d - 1), d - 1, k)


print(f(N, len(N), K))
