N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(1, N + 1):
    a.append(a[i - 1] * 2 + 3)
    p.append(p[i - 1] * 2 + 1)


def F(n, x):
    if n == 0:
        return 1
    if x == 1:
        return 0
    elif x <= 1 + a[n - 1]:
        return F(n - 1, x - 1)
    elif x == 2 + a[n - 1]:
        return p[n - 1] + 1
    elif x <= 2 + 2 * a[n - 1]:
        return p[n - 1] + 1 + F(n - 1, x - 2 - a[n - 1])
    else:
        return 2 * p[n - 1] + 1

print(F(N, X))

