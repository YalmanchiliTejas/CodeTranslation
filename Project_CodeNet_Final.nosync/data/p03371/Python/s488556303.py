def main():
    a, b, c, x, y = map(int, input().split())
    res = a * x + b * y
    for n_c in range(2, 2 * max(x, y) + 1, 2):
        xx = x - n_c // 2
        yy = y - n_c // 2
        p = a * max(xx, 0) + b * max(yy, 0) + c * n_c
        res = min(res, p)
    print(res)


if __name__ == '__main__':
    main()
