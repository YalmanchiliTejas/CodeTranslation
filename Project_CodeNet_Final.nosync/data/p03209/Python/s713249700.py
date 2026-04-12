def f(n, x, a, p):
    if n == 0:
        return 1 if x > 0 else 0
    elif x <= 1 + a[n - 1]:
        return f(n - 1, x - 1, a, p)
    else:
        return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1], a, p)


def main():
    N, X = list(map(int, input().split(' ')))
    a, p = [1], [1]
    for i in range(N):
        a.append(a[i] * 2 + 3)
        p.append(p[i] * 2 + 1)
    print(f(N, X, a, p))


if __name__ == '__main__':
    main()
