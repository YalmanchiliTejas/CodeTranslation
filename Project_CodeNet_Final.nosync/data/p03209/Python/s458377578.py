n, x = map(int, input().split())
p = [1] * n
c = [1] * n
for i in range(1, n):
    p[i] = 2 * p[i - 1] + 1
    c[i] = 2 * c[i - 1] + 3


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= c[N - 1] + 1:
        return f(N - 1, X - 1)
    else:
        return f(N - 1, X - c[N - 1] - 2) + p[N - 1] + 1


ans = f(n, x)
print(ans)