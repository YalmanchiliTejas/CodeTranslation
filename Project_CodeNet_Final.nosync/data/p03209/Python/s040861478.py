def f(n, x, a, p):
    if n == 0:
        return 1 if x == 1 else 0

    elif x <= 1:
        return 0

    elif 1 < x <= 1 + a[n - 1]:
        return f(n - 1, x - 1, a, p)

    elif x == 2 + a[n - 1]:
        return p[n - 1] + 1

    elif 2 + a[n - 1] < x <= 2 + 2 * a[n - 1]:
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1], a, p)

    else:
        return 1 + 2 * p[n - 1]


n, x = map(int, input().split())

a = [1] * (n + 1)
p = [1] * (n + 1)

for i in range(1, n + 1):
    a[i] = 3 + 2 * a[i - 1]
    p[i] = 1 + 2 * p[i - 1]

print(f(n, x, a, p))

