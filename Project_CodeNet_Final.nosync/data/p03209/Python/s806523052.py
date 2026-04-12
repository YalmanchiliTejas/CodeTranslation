n, x = map(int, input().split())

p = [1]
h = [1]

for i in range(50):
    p.append(1 + p[-1] * 2)
    h.append(3 + h[-1] * 2)


def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1

    if x <= 1 + h[n - 1]:
        return f(n - 1, x - 1)

    return p[n - 1] + 1 + f(n - 1, x - 2 - h[n - 1])


print(f(n, x))
