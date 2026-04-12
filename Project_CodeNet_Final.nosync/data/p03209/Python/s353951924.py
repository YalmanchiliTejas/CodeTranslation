N, X = map(int, input().split())

a, p = [1], [1]
for i in range(N-1):
    a.append(3 + 2 * a[i])
    p.append(1 + 2 * p[i])


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= a[N-1] + 1:
        return f(N-1, X-1)
    else:
        return p[N-1] + 1 + f(N-1, X - (a[N-1]+2))

print(f(N, X))	