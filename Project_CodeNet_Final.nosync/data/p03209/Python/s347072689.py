def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= a[N - 1] + 1:
        return f(N - 1, X - 1)
    else:
        return 1 + p[N - 1] + f(N - 1, X - 1 - a[N - 1] - 1)


N, X = map(int, input().strip().split(" "))

a, p = [1], [1]
for i in range(N):
    a.append(2 * a[i] + 3)
    p.append(2 * p[i] + 1)

print(f(N, X))