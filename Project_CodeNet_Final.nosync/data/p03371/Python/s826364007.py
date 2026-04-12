def main():
    import math

    a, b, c, x, y = map(int, input().split())
    d = [a, b]
    i, j = min(x, y), max(x, y)
    n = math.ceil(i / 2)
    f = j == x
    if 2 * c > (a + b):
        ans = a * x + b * y
    else:
        ans = 2 * c * i + (j - i) * min(c * 2, d[not f])

    print(ans)


if __name__ == '__main__':
    main()
