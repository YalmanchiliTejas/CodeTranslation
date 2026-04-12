
N, X = map(int, input().split())

a = [1] * (N + 1)
p = [1] * (N + 1)
for i in range(N):
    a[i + 1] = a[i] * 2 + 3
    p[i + 1] = p[i] * 2 + 1


def func(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + a[n - 1]:
        return func(n - 1, x - 1)

    return p[n - 1] + 1 + func(n - 1, x - 2 - a[n - 1])


print(func(N, X))
