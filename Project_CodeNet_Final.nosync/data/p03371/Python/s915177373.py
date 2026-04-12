def resolve():
    a, b, c, x, y = map(int, input().split())

    n_c = min(x, y)

    if (n_c * 2) * c < n_c * (a + b):
        if x - y >= 0:
            if a/2 < c:
                print(n_c * 2 * c + (x - y) * a)
            else:
                print(n_c * 2 * c + (x - y) * 2 * c)
        else:
            if b/2 < c:
                print(n_c * 2 * c + (y - x) * b)
            else:
                print(n_c * 2 * c + (y - x) * 2 * c)
    else:
        print(a * x + b * y)


if __name__ == "__main__":
    resolve()