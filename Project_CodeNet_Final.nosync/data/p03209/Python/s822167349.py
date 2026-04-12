N, X = map(int, input().split())

a, p = [1], [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)


def f(N, X):
    if N == 0:
        return 1 if X >= 1 else 0

    else:
        if X == 1 or 0:
            return 0
        elif X <= a[N - 1] + 1:
            return f(N - 1, X - 1)
        elif X == a[N - 1] + 2:
            return p[N - 1] + 1
        else:
            return p[N] - f(N, a[N] - X)


print(f(N, X))
