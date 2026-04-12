def main():
    n, x = map(int, input().split())

    # p_n = 1 + 2 * p_n-1
    # l_n = 3 + 2 * p_n-1
    # p0 = 1
    # l0 = 1
    pl = [(0, 0)] * (n + 1)
    pl[0] = (1, 1)

    for i in range(1, n + 1):
        prv = pl[i - 1]
        pl[i] = (1 + 2 * prv[0], 3 + 2 * prv[1])

    res = 0

    while n and x > 0:
        x -= 1  # bands
        p, l = pl[n - 1]
        if x == l * 2 + 2 or x == l * 2 + 1:
            res += 2 * p + 1
            break

        if x == l or x == l + 1:
            res += p + (x - l)
            break

        if x < l:
            n -= 1
        else:
            res += p + 1
            x -= l

    print(res)


if __name__ == '__main__':
    main()
