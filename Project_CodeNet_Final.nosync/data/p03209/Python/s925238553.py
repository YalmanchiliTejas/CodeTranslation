def main():
    n, x = map(int, input().split())

    # p_n = 1 + 2 * p_n-1
    # l_n = 3 + 2 * p_n-1
    # p0 = 1
    # l0 = 1
    p = [0] * (n + 1)
    l = [0] * (n + 1)
    p[0] = 1
    l[0] = 1
    for i in range(1, n + 1):
        p[i] = 1 + 2 * p[i - 1]
        l[i] = 3 + 2 * l[i - 1]

    res = 0
    while n and x > 0:
        x -= 1  # bands

        if x == l[n - 1] or x == l[n - 1] + 1:
            res += p[n - 1] + (x - l[n - 1])
            break
        if x == l[n - 1] * 2 + 2:
            res += 2 * p[n - 1] + 1
            break
        if x < l[n - 1]:
            n -= 1
        else:
            res += p[n - 1] + 1
            x -= l[n - 1]

    print(res)


if __name__ == '__main__':
    main()
