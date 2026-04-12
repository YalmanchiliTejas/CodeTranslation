N, X = map(int, input().split())

a, p = [None] * (N + 1), [None] * (N + 1)
a[0], p[0] = 1, 1
for i in range(1, N + 1):
    a[i], p[i] = 2 * a[i - 1] + 3, 2 * p[i - 1] + 1


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= a[N - 1] + 1:
        return f(N - 1, X - 1)
    else:
        return p[N - 1] + 1 + f(N - 1, X - a[N - 1] - 2)

print(f(N, X))
