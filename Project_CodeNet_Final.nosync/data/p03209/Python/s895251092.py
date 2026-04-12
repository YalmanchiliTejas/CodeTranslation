def f(i, X):
    if i == 0:
        return 1

    elif X == 1:
        return 0

    elif X <= 1 + a[i-1]:
        return f(i-1, X-1)

    elif X == 2 + a[i-1]:
        return p[i-1] + 1

    elif X <= 2 + 2 * a[i-1]:
        return f(i-1, X-2-a[i-1]) + 1 + p[i-1]

    else:
        return p[i]

N, X = map(int, input().split())
a = [1]
p = [1]
for i in range(N):
    a.append(2 * a[-1] + 3)
    p.append(2 * p[-1] + 1)

print(f(N, X))