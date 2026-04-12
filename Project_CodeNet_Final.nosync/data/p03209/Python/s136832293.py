N, X = map(int, input().split())

a = [1]  # レベルiバーガーの長さ
p = [1]  # レベルiバーガーに含まれるパティの数
for i in range(N):
    a.append(2 * a[-1] + 3)
    p.append(2 * p[-1] + 1)


def f(N, X):
    if N == 0:
        return 0 if X <= 0 else 1

    elif X <= 1 + a[N - 1]:
        return f(N - 1, X - 1)

    else:
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1])


print(f(N, X))
